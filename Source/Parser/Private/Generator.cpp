#include "Generator.h"
#include "crc.h"
#include "PlatformFilemanager.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "FileHelper.h"
#include "TlParser.h"
#include "SourceBuilder.h"
#include "Regex.h"
#include "FileManager.h"

#include <iostream>
#include <fstream>
#include "../Source/Parser/TL/TLObjectBase.h"


int writeFile(FString str, FString FileName)
{
	std::ofstream myfile;
	myfile.open(std::string(TCHAR_TO_UTF8(*FileName)).c_str(), std::ios::app);
	myfile << std::string(TCHAR_TO_UTF8(*str)).c_str();
	myfile.close();
	return 0;
}

FString CamalCase(FString ClassName)
{
	FRegexPattern Pattern(
		TEXT("((?i)[a-z]+\\d?)_*")
	);
	FRegexMatcher Match(Pattern, ClassName);

	FString CamalClassName;
	while (Match.FindNext())
	{
		FString tmp = Match.GetCaptureGroup(1);
		tmp[0] = toupper(tmp[0]);
		CamalClassName += tmp;
	}
	return CamalClassName;
}

// Delete all TLObjects (Types/Functions/AllObjects.h)
void TLGenerator::CleanTLObjects()
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString GameDir = FPaths::GameDir();
	FString PluginDir = GameDir + TEXT("Plugins/Parser/");
	FString PluginContentDir = PluginDir + TEXT("TL/");
	FString FuncDir = PluginContentDir + TEXT("Functions/");
	FString TypesDir = PluginContentDir + TEXT("Types/");

	if (PlatformFile.FileExists(*(PluginContentDir + TEXT("AllObjects.h"))))
		PlatformFile.DeleteFile(*(PluginContentDir + TEXT("AllObjects.h")));

	if(PlatformFile.DirectoryExists(*FuncDir))
		PlatformFile.DeleteDirectoryRecursively(*FuncDir);
	if (PlatformFile.DirectoryExists(*TypesDir))
		PlatformFile.DeleteDirectoryRecursively(*TypesDir);


}


void TLGenerator::GenerateTLObjects(FString SchemeFile, uint32 ImportDepth)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString GameDir = FPaths::GameDir();
	FString PluginDir = GameDir + TEXT("Plugins/Parser/");
	FString PluginContentDir = PluginDir + TEXT("TL/");
	FString FuncDir = PluginContentDir + TEXT("Functions/");
	FString TypesDir = PluginContentDir + TEXT("Types/");

	//Create directory for Functions
	if (!PlatformFile.DirectoryExists(*FuncDir))
		PlatformFile.CreateDirectory(*FuncDir);

	//Create directory for Types
	if (!PlatformFile.DirectoryExists(*TypesDir))
		PlatformFile.CreateDirectory(*TypesDir);

	//Check for scheme file exists
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*SchemeFile))
	{
		_LOG("File %s not exist", *SchemeFile);
	}
	else
	{
		//Parse scheme file to detect TLObjects (Functions and Types)
		auto TLObjects = TLParser::ParseFile(SchemeFile);
		
		TArray<FString> AllNames;
		TArray<FString> AbstractTypes;
		TArray<FString> CommonNames;

		for (auto tl : TLObjects)
		{
			AllNames.AddUnique(tl.Name());

			if (tl.Namespace() == TEXT("COMMON"))
				CommonNames.AddUnique(tl.Name());
		}

		for (auto tl : TLObjects)
		{
			//if (!tl.IsFunction())
			{
				auto Type = tl.Result();

// 				if (tl.ID() == "c04cfac2")
// 					_LOG("");

				FRegexPattern TypePattern(TEXT("TArray<([\\w[\\s|^\\s]]+)>"));
				FRegexMatcher TypeMatch(TypePattern, Type);

				FString _Name;
				FString _Namespace;
				if (Type.Contains(TEXT("::")))
				{
					Type.Split("::", &_Namespace, &_Name);
					if (!AllNames.Contains(_Name) && 
						!TypeMatch.FindNext() && 
						!_Name.Contains(TEXT("TLBaseObject")) && 
						_Name != ("bool") && 
						!tl.SystemTypes().Contains(_Name)
						)
						AbstractTypes.AddUnique(_Name);
				}
				else if (!AllNames.Contains(Type) && 
					!TypeMatch.FindNext() && 
					!Type.Contains(TEXT("TLBaseObject")) && 
					Type != ("bool") && 
					!tl.SystemTypes().Contains(Type)
					)
					AbstractTypes.AddUnique(Type);
			}
		}

// 		for (auto AbsType : AbstractTypes)
// 		{
// 			this->WriteAbstractClass(AbsType, FPaths::Combine(TypesDir, FString("PRIVATE")));
// 		}

		TLSourceBuilder sb;
		sb.WriteLine(TEXT("#pragma once"));
		sb.WriteLine(TEXT("#include \"Engine.h\""));

		for (auto tl : TLObjects)
		{
			if (/*tl.IsCoreType() ||*/ (tl.Name().IsEmpty() && tl.Namespace().IsEmpty()))
				continue;

			if (tl.IsFunction())
				this->_OutputDir = FuncDir;
			else
				this->_OutputDir = TypesDir;

			auto Depth = ImportDepth;
			Depth += 1;
			this->_OutputDir = FPaths::Combine(this->_OutputDir, tl.Namespace());

			if (!PlatformFile.DirectoryExists(*this->_OutputDir))
			{
				PlatformFile.CreateDirectory(*this->_OutputDir);
				PlatformFile.CreateDirectory(*(FPaths::Combine(this->_OutputDir, FString(TEXT("Private")))));
				PlatformFile.CreateDirectory(*(FPaths::Combine(this->_OutputDir, FString(TEXT("Public")))));
			}

			auto HeaderFilePath = FPaths::Combine(this->_OutputDir, FString(TEXT("Public")));
			this->WriteHeaderCode(HeaderFilePath, tl, AbstractTypes, CommonNames, Depth);

			auto SourceFilePath = FPaths::Combine(this->_OutputDir, FString(TEXT("Private")));
			this->WriteSourceCode(SourceFilePath, tl, AbstractTypes, CommonNames, Depth);
			
			if (tl.IsFunction())
				sb.WriteLine(TEXT("#include \"Functions/") + tl.Namespace() + TEXT("/Public/") + tl.Name() + TEXT(".h\""));
			else
				sb.WriteLine(TEXT("#include \"Types/") + tl.Namespace() + TEXT("/Public/") + tl.Name() + TEXT(".h\""));
		}

		sb.WriteLine(TEXT("\n"));
		sb.WriteLine(TEXT("TMap<int32, TLBaseObject*> GetAllObjects()"));
		sb.WriteLine(TEXT("{"));
		sb.WriteLine(TEXT("\tTMap<int32, TLBaseObject*> AllObjects;"));
		for (auto tl : TLObjects)
			sb.WriteLine(TEXT("\tAllObjects.Add(") + FString::FromInt(tl.ID()) + TEXT(", new ") + tl.Namespace() + TEXT("::") + tl.Name() + TEXT("());"));
		sb.WriteLine(TEXT("\treturn AllObjects;"));
		sb.WriteLine(TEXT("}"));
		auto FilePath = FPaths::Combine(PluginContentDir, FString(TEXT("AllObjects.h")));
		if (PlatformFile.FileExists(*FilePath))
			PlatformFile.DeleteFile(*FilePath);
		else
			FFileHelper::SaveStringToFile(sb.ReturnGeneratedCode(), *FilePath);
	}
}

FString TLGenerator::GetFileName(TLObject tl)
{
	return "";
}

FString TLGenerator::GetFile(FString Path)
{
	return _OutputDir + Path;
}

void TLGenerator::WriteHeaderCode(FString HeaderFilePath, TLObject& tl, TArray<FString> AbstractClasses, TArray<FString> CommonClasses, uint32 Depth)
{
	FString UsingDepth = TEXT("../");
	for (uint32 i = 0; i < Depth; i++)
		UsingDepth += TEXT("../");

	FString FileName = FPaths::Combine(HeaderFilePath, tl.Name()) + TEXT(".h");

	FString HeaderCode;

	FString UpperResultType;

	FString Namespaces;

	FString UpperName = tl.Name();
	FString UpperNamespace = tl.Namespace();

	TLSourceBuilder sb;

	TArray<FString> CompareTypes;
	FString Args;


	if (tl.Args().Num())
	{
		for (auto &Arg : tl.Args())
		{
			if (Arg.Type().IsEmpty())
				continue;

			auto Type = Arg.Type();
			FString _Namespace;


			if (Type.Contains("::"))
			{
				Type.Split("::", &_Namespace, &Type);
				_Namespace.ToUpperInline();
				Type[0] = toupper(Type[0]);
			}

			if (Arg.SystemTypes().Contains(Arg.Name()))
			{
				auto Tmp = Arg.Name();
				Tmp[0] = toupper(Tmp[0]);
				Arg.SetName(Tmp);
			}
			
			if(!Arg.SystemTypes().Contains(Arg.Type()))
			{
				Type[0] = toupper(Type[0]);
			}

			if (AbstractClasses.Contains(Type) && !Arg.IsVector())
			{
				Args += /*TEXT("PRIVATE::") + Type +*/ TEXT("TLBaseObject* ") + Arg.Name();
				Arg.SetType(/*TEXT("PRIVATE::") + Arg.Type() + */TEXT("TLBaseObject* "));
// 				if (!CompareTypes.Contains(Type))
// 					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Private/") + Type + TEXT(".h\"");
			}
			else if (Arg.Type() == TEXT("TLBaseObject"))
			{
				Args += Type + TEXT("* ") + Arg.Name();
				Arg.SetType(Arg.Type() + TEXT("* "));
			}
			else if (Arg.IsBytes())
			{
				Args += TEXT("TArray<") + Type + TEXT("> ") + Arg.Name();
				Arg.SetType(TEXT("TArray<") + Type + TEXT("> "));
			}
			else if (Type == TEXT("FDateTime"))
			{
				Args += Type + " " + Arg.Name();
			}
			else if (Arg.IsVector() && AbstractClasses.Contains(Type))
			{
				Args += TEXT("TArray<TLBaseObject*> ") + Arg.Name();
				Arg.SetType(TEXT("TArray<TLBaseObject*> "));
				//Args += TEXT("TArray<PRIVATE::") + Type + TEXT("*> ") + Arg.Name();
				//Arg.SetType(TEXT("TArray<PRIVATE::") + Type + TEXT("*> "));
// 				if (!CompareTypes.Contains(Type))
// 					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Private/") + Type + TEXT(".h\"");
			}
			else if (Arg.IsVector() && !AbstractClasses.Contains(Type))
			{
				if (!Arg.SystemTypes().Contains(Type))
				{
					if (CommonClasses.Contains(Type) && _Namespace.IsEmpty())
					{
						Args += TEXT("TArray<COMMON::") + Type + TEXT("*> ") + Arg.Name();
						Arg.SetType(TEXT("TArray<COMMON::") + Type + TEXT("*> "));
						if (!CompareTypes.Contains(Type))
							Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Common/Public/") + Type + TEXT(".h\"");
					}
					else
					{
						Args += TEXT("TArray<") + _Namespace + TEXT("::") + Type + TEXT("*> ") + Arg.Name();
						Arg.SetType(TEXT("TArray<") + _Namespace + TEXT("::") + Type + TEXT("*> "));
						if (!CompareTypes.Contains(Type))
							Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/") + _Namespace + ("/Public/") + Type + TEXT(".h\"");
					}
					//Arg.Type(TEXT("TArray<COMMON::") + Type + TEXT("> "));

				}
				else
				{
					Args += TEXT("TArray<") + Type + TEXT("> ") + Arg.Name();
					Arg.SetType(TEXT("TArray<") + Type + TEXT("> "));
				}
			}
			else if (Arg.Type() == TEXT("true") || Type.Contains(TEXT("bool")))
			{
				Args += TEXT("bool ") + Arg.Name();
				//Arg.SetType(TEXT("bool"));
			}
			else if (!AbstractClasses.Contains(Type) && !Arg.SystemTypes().Contains(Type) && !Arg.IsVector() && !Arg.IsBytes())
			{
				if (CommonClasses.Contains(Type) && _Namespace.IsEmpty())
				{
					Args += TEXT("COMMON::") + Type + TEXT("* ") + Arg.Name();
					Arg.SetType(TEXT("COMMON::") + Type + TEXT("* "));
					if (!CompareTypes.Contains(Type))
						Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Common/Public/") + Type + TEXT(".h\"");
				}
				else
				{
					Args += _Namespace + TEXT("::") + Type + TEXT("* ") + Arg.Name();
					Arg.SetType(_Namespace + TEXT("::") + Type + TEXT("* "));
					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/") + _Namespace + ("/Public/") + Type + TEXT(".h\"");
				}
				//Arg.Type(TEXT("COMMON::") + Arg.Type());

			}
			else if (Arg.SystemTypes().Contains(Type) && !Arg.IsBytes())
			{
				if (Arg.Type() == TEXT("TBigInt<256>") || Arg.Type() == TEXT("TBigInt<128>"))
					if (!CompareTypes.Contains(Type))
						Namespaces += TEXT("\n#include \"BigInt.h\"");
				Args += Type + TEXT(" ") + Arg.Name();
			}


			Args += TEXT(", ");

			CompareTypes.AddUnique(Type);
		}
	}

	Args.RemoveFromEnd(TEXT(", "));


	FString InheritFrom;
	FString IncludeFile;
	FString IncludeNamespace;
	FString TypeNamespace;
	FString ResultTypeName;

	if (tl.Result().Contains(TEXT("::")))
	{
		tl.Result().Split(TEXT("::"), &TypeNamespace, &ResultTypeName);
		if (AbstractClasses.Contains(ResultTypeName))
		{
			//InheritFrom = TEXT("PRIVATE::") + ResultTypeName;
			//IncludeFile = TEXT("Types/Private/") + ResultTypeName + TEXT(".h");
			InheritFrom = TEXT("TLBaseObject");
			IncludeFile = TEXT("TLObjectBase.h");
		}
		else
		{
			InheritFrom = TEXT("TLBaseObject");
			IncludeFile = TEXT("TLObjectBase.h");
			//IncludeNamespace = TEXT("Types/") + TypeNamespace + TEXT("/Public/") + ResultTypeName + TEXT(".h");
		}
	}
	else
	{
		ResultTypeName = tl.Result();
		if (AbstractClasses.Contains(ResultTypeName))
		{
// 			InheritFrom = TEXT("PRIVATE::") + ResultTypeName;
// 			if (ResultTypeName != tl.Name())
// 				IncludeFile = TEXT("Types/Private/") + ResultTypeName + (".h");
			InheritFrom = TEXT("TLBaseObject");
			IncludeFile = TEXT("TLObjectBase.h");
		}
		else
		{
			InheritFrom = TEXT("TLBaseObject");
			IncludeFile = TEXT("TLObjectBase.h");
			//IncludeNamespace = TEXT("Types/Common/Public/") + ResultTypeName + TEXT(".h");
		}
	}

	if (!tl.SystemTypes().Contains(tl.Result()))
	{
		FString TMPName;
		FString TMPNamespace;
		if (tl.Result().Contains(TEXT("::")))
		{
			tl.Result().Split(TEXT("::"), &TMPNamespace, &TMPName);
			if (AbstractClasses.Contains(TMPName))
			{
// 				if (TMPName != tl.Name())
// 					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Private/") + TMPName + TEXT(".h\"");
				tl.SetResult(TEXT("TLBaseObject*"));
			}
			else
			{
				tl.SetResult(TMPNamespace.ToUpper() + "::" + TMPName + TEXT("*"));
				if (TMPName != tl.Name())
					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/") + TMPNamespace + TEXT("/Public/") + TMPName + TEXT(".h\"");
			}
		}
		else
		{
			if (AbstractClasses.Contains(tl.Result()))
			{
// 				if (tl.Result() != tl.Name())
// 					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Private/") + tl.Result() + TEXT(".h\"");
				tl.SetResult(TEXT("TLBaseObject*"));
			}
			else
			{
				if (tl.Result().Contains(TEXT("TArray<")))
				{
					FRegexPattern VectorPattern(TEXT("TArray<([\\w[\\s|^\\s]]+)>"));
					FRegexMatcher VectorMatch(VectorPattern, tl.Result());

					if (VectorMatch.FindNext())
						tl.SetResult(VectorMatch.GetCaptureGroup(1));

					if (AbstractClasses.Contains(tl.Result()))
					{
// 						if (tl.Result() != tl.Name())
// 							Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Private/") + tl.Result() + TEXT(".h\"");
						tl.SetResult(TEXT("TArray<TLBaseObject*>"));
					}
					else if (CommonClasses.Contains(tl.Result()))
					{
						if (tl.Result() != tl.Name())
							Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Common/Public/") + tl.Result() + TEXT(".h\"");
						tl.SetResult(TEXT("TArray<COMMON::") + tl.Result() + TEXT("*>"));
					}
					else if (tl.SystemTypes().Contains(tl.Result()))
						tl.SetResult(TEXT("TArray<") + tl.Result() + TEXT(">"));
					else
					{
						FString _Name;
						FString _Namespace;
						tl.Result().Split("::", &_Namespace, &_Name);
						if (tl.Result() != tl.Name())
							if (!_Namespace.IsEmpty())
								Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/") + _Namespace + TEXT("/Public/") + _Name + TEXT(".h\"");
						tl.SetResult(TEXT("TArray<") + tl.Result() + TEXT("*>"));
					}


				}
				else
				{
					if (CommonClasses.Contains(tl.Result()))
					{
						if (tl.Result() != tl.Name())
							Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Common/Public/") + tl.Result() + TEXT(".h\"");
						tl.SetResult(TEXT("COMMON::") + tl.Result() + TEXT("*"));
					}
					else if (tl.SystemTypes().Contains(tl.Result()))
						tl.SetResult(TEXT("") + tl.Result() + TEXT(""));
					else
					{
						tl.SetResult(TEXT("") + tl.Result() + TEXT("*"));
					}
				}
			}
		}
	}


	sb.WriteLine(TEXT("#pragma once"));
	sb.WriteLine(TEXT("#include \"Engine.h\""));
	if (!IncludeFile.IsEmpty())
		sb.WriteLine(TEXT("#include \"") + UsingDepth + IncludeFile + TEXT("\""));

	if (!Namespaces.IsEmpty())
		sb.WriteLine(Namespaces);

	if (!tl.Namespace().IsEmpty())
	{
		sb.WriteLine(TEXT("\n//begin namespace block"));
		sb.WriteLine(TEXT("namespace ") + UpperNamespace);
		sb.WriteLine(TEXT("{"));
	}

	sb.WriteLine(TEXT("class ") + UpperName + TEXT(" : public ") + InheritFrom + TEXT("\n{"));
	sb.WriteLine(TEXT("public:"));
	sb.WriteLine(TEXT("\t") + UpperName + TEXT("();"));

	if (!Args.IsEmpty())
	{
		sb.WriteLine(TEXT("\t") + UpperName + TEXT("(") + Args + TEXT(");"));

		sb.WriteLine(TEXT(""));

	}
	sb.WriteLine(TEXT("\t~") + UpperName + TEXT("();"));
	// 	sb.WriteLine("FString ConstructorID() const");
	// 	sb.WriteLine("{");
	// 	sb.WriteLine("\t return _ConstructorID;");
	// 	sb.WriteLine("}\n");

	sb.WriteLine(TEXT("\tvirtual void OnSend(BinaryWriter& Writer) override;"));
	sb.WriteLine(TEXT("\tvirtual void OnResponce(BinaryReader& Reader) override;"));
	sb.WriteLine(TEXT(""));

	for (auto Arg : tl.Args())
	{
		if(!Arg.IsFlagIndicator())
		{
			FString ArgName;
			if (Arg.Name().Contains(TEXT("_")))
				ArgName = CamalCase(Arg.Name());
			else
				ArgName = Arg.Name();

			if (Arg.Type() == TEXT("true") || Arg.Type().Contains(TEXT("bool")))
				sb.WriteLine(TEXT("\tbool Get") + ArgName + TEXT("() const"));
			else
				sb.WriteLine(TEXT("\t") + Arg.Type() + TEXT(" Get") + ArgName + TEXT("() const"));

			sb.WriteLine(TEXT("\t{"));
			sb.WriteLine(TEXT("\t\t return this->") + Arg.Name() + TEXT(";"));
			sb.WriteLine(TEXT("\t}\n"));
		}
	}
	

	if (tl.IsFunction())
	{
		if (tl.Result() == TEXT("true") || tl.Result().Contains(TEXT("bool")))
			sb.WriteLine(TEXT("\tbool GetResult() const"));
		else
			sb.WriteLine(TEXT("\t") + tl.Result() + TEXT(" GetResult() const"));

		sb.WriteLine(TEXT("\t{"));
		sb.WriteLine(TEXT("\t\t return this->result;"));
		sb.WriteLine(TEXT("\t}\n"));
	}

	sb.WriteLine(TEXT("private:"));
	
	if (!Args.IsEmpty())
	{
		TArray<FString> SplitArgs;
		Args.ParseIntoArray(SplitArgs, TEXT(","));

		for (auto Line : SplitArgs)
			sb.WriteLine(TEXT("\t") + Line + TEXT(";"));
	}

	if (tl.IsFunction())
	{
		if (tl.Result() == TEXT("true"))
			sb.WriteLine(TEXT("\tbool result;"));
		else 
			sb.WriteLine(TEXT("\t") + tl.Result() + TEXT(" result;"));
	}

	sb.WriteLine(TEXT("};"));

	if (!tl.Namespace().IsEmpty())
	{
		sb.WriteLine(TEXT("} //end namespace block"));
	}

	HeaderCode = sb.ReturnGeneratedCode();

	FFileHelper::SaveStringToFile(HeaderCode, *FileName);
}

void TLGenerator::WriteSourceCode(FString SourceFilePath, TLObject& tl, TArray<FString> AbstractClasses, TArray<FString> CommonClasses, uint32 Depth)
{
	TLSourceBuilder sb;
	FString SourceCode;
	FString UpperName = tl.Name();

	sb.WriteLine(TEXT("#include \"../Public/" + tl.Name() + ".h\"\n\n"));
	
	//Checking for namespaces
	if(!tl.Namespace().IsEmpty())
	{
		FString UpperNamespace = tl.Namespace();
		sb.WriteLine(TEXT("//begin namespace block"));
		sb.WriteLine(TEXT("namespace ") + UpperNamespace + TEXT("\n{"));
	}

	//Default constructor generation
	sb.WriteLine(TEXT("\n") + UpperName + TEXT("::") + UpperName + TEXT("()"));
	sb.WriteLine(TEXT("{"));
	sb.WriteLine(TEXT("\tthis->_ConstructorID = ") + FString::FromInt(tl.ID()) + TEXT(";"));
	if (tl.IsFunction())
		sb.WriteLine(TEXT("\tthis->_ContentRelated = true;"));
	sb.WriteLine(TEXT("}"));
	//Detecting arguments
	FString Args;
	if (tl.Args().Num())
	{
		for (auto &Arg : tl.Args())
		{
			if (Arg.Type().IsEmpty())
				continue;

			auto Type = Arg.Type();
			FString _Namespace;


			if (!Arg.SystemTypes().Contains(Arg.Type()))
			{
				Type[0] = toupper(Type[0]);
			}

			if (AbstractClasses.Contains(Type) && !Arg.IsVector())
			{
				Args += /*TEXT("PRIVATE::") + Type + */TEXT("TLBaseObject* ") + Arg.Name();
				//Arg.Type(TEXT("PRIVATE::") + Arg.Type());
			}
			else if (Arg.IsBytes())
			{
				Args += /*TEXT("TArray<") +*/ Type + TEXT(" ") + Arg.Name();
				//Arg.Type(TEXT("TArray<") + Type + TEXT("> "));
			}
			else if (Type == TEXT("FDateTime"))
			{
				Args += Type + TEXT(" ") + Arg.Name();
			}
			else if (Arg.IsVector() && AbstractClasses.Contains(Type))
			{
				Args += TEXT("TArray<TLBaseOblect*>") + Arg.Name();
				//Arg.Type(TEXT("TArray<PRIVATE::") + Type + TEXT("> "));
			}
			else if (Arg.IsVector() && !AbstractClasses.Contains(Type))
			{
				if (!Arg.SystemTypes().Contains(Type))
				{
					if (CommonClasses.Contains(Type) && _Namespace.IsEmpty())
						Args += /*TEXT("TArray<COMMON::") +*/ Type + TEXT(" ") + Arg.Name();
					else
						Args +=/* TEXT("TArray<") + _Namespace + TEXT("::") + */Type + TEXT(" ") + Arg.Name();
					//Arg.Type(TEXT("TArray<COMMON::") + Type + TEXT("> "));
				}
				else
				{
					Args += /*TEXT("TArray<") + */Type + TEXT(" ") + Arg.Name();
					//Arg.Type(TEXT("TArray<") + Type + TEXT("> "));
				}
			}
			else if (Arg.Type() == TEXT("true") || Type.Contains(TEXT("bool")))
			{
				Args += TEXT("bool ") + Arg.Name();
				//Arg.Type(TEXT("bool"));
			}
			else if (!AbstractClasses.Contains(Type) && !Arg.SystemTypes().Contains(Type) && !Arg.IsVector() && !Arg.IsBytes())
			{
				if (CommonClasses.Contains(Type) && _Namespace.IsEmpty())
				{
					Args +=/* TEXT("COMMON::") + */Type + TEXT(" ") + Arg.Name();
				}
				else
				{
					Args += /*_Namespace + TEXT("::") +*/ Type + TEXT(" ") + Arg.Name();
				}
				//Arg.Type(TEXT("COMMON::") + Arg.Type());

			}
			else if (Arg.SystemTypes().Contains(Type) && !Arg.IsBytes())
			{
				Args += Type + TEXT(" ") + Arg.Name();
			}


			Args += TEXT(", ");
		}
	}

	Args.RemoveFromEnd(TEXT(", "));

	//Constructor with parameters generation 
	if (!Args.IsEmpty())
	{
		sb.WriteLine(TEXT("\n") + UpperName + TEXT("::") + UpperName + TEXT("(") + Args + TEXT(")"));
		sb.WriteLine(TEXT("{"));
		sb.WriteLine(TEXT("\tthis->_ConstructorID = ") + FString::FromInt(tl.ID()) + TEXT(";"));
		if (tl.IsFunction())
			sb.WriteLine(TEXT("\tthis->_ContentRelated = true;"));
		for (auto Arg : tl.Args())
		{
			if (!Arg.IsFlagIndicator())
				sb.WriteLine(TEXT("\tthis->") + Arg.Name() + TEXT(" = ") + Arg.Name() + TEXT(";"));
		}
		sb.WriteLine(TEXT("}"));
	}

	//OnSend Function Generation 
	sb.WriteLine(TEXT("void ") + UpperName + TEXT("::OnSend(BinaryWriter& Writer)"));
	sb.WriteLine(TEXT("{"));
	sb.WriteLine(TEXT("\tWriter.WriteInt(this->_ConstructorID);"));
	for (auto Arg : tl.Args())
		this->WriteOnSendCode(sb, Arg, tl.Args());
	sb.WriteLine(TEXT("}\n\n"));

	//OnResponce Function Generation 
	sb.WriteLine(TEXT("void ") + UpperName + TEXT("::OnResponce(BinaryReader& Reader)"));
	sb.WriteLine(TEXT("{"));
	if (tl.IsFunction())
		this->WriteRequestResultCode(sb, tl);
	else
	{
		if (tl.Args().Num() != 0)
		{
			for (auto Arg : tl.Args())
				this->WriteOnResponceCode(sb, tl, Arg, tl.Args(), AbstractClasses, CommonClasses);
		}
		else
		{
			sb.WriteLine(TEXT("\t{\n\t//pass\n\t}"));
		}
	}
	sb.WriteLine(TEXT("\tthis->_Responded = true;"));
	sb.WriteLine(TEXT("}"));

	//Destructor generation
	sb.WriteLine(UpperName + TEXT("::~") + UpperName + TEXT("()"));
	sb.WriteLine(TEXT("{"));

	for (auto Arg : tl.Args())
	{
		if (!Arg.IsVector() && !Arg.IsBytes() && !Arg.SystemTypes().Contains(Arg.Type()) && Arg.Type().Contains(TEXT("*")))
		{
			sb.WriteLine(TEXT("\tif(this->" + Arg.Name() + ")"));
			sb.WriteLine(TEXT("\t{"));
			sb.WriteLine(TEXT("\t\tdelete this->" + Arg.Name() + ";"));
			sb.WriteLine(TEXT("\t}"));
		}
	}

	if(tl.IsFunction() && !tl.Result().Contains(TEXT("TArray")) && !tl.SystemTypes().Contains(tl.Result()) && tl.Result().Contains(TEXT("*")))
	{	
		sb.WriteLine(TEXT("\tif(this->result)"));
		sb.WriteLine(TEXT("\t{"));
		sb.WriteLine(TEXT("\t\tdelete this->result;"));
		sb.WriteLine(TEXT("\t}"));
	}
	
	sb.WriteLine(TEXT("}"));

	//put enclosing scope for namespace if needed
	if(!tl.Namespace().IsEmpty())
		sb.WriteLine(TEXT("}//end namespace block"));

	//Return generated code as string
	SourceCode = sb.ReturnGeneratedCode();

	//Combine file path and class name to create source file 
	FString FileName = FPaths::Combine(SourceFilePath, tl.Name()) + ".cpp";

	//Save source file 
	FFileHelper::SaveStringToFile(SourceCode, *FileName);
}

void TLGenerator::WriteAbstractClass(FString ClassName, FString FilePath)
{
	TLSourceBuilder sb;
	
	sb.WriteLine(TEXT("#pragma once"));
	sb.WriteLine(TEXT("#include \"Engine.h\""));
	sb.WriteLine(TEXT("#include \"../../TLObjectBase.h\""));
	sb.WriteLine(TEXT("#include \"../../Public/extensions/BinaryReader.h\""));
	sb.WriteLine(TEXT("#include \"../../Public/extensions/BinaryWriter.h\""));


	sb.WriteLine(TEXT("\nnamespace PRIVATE \n{"));


	sb.WriteLine(TEXT("\nclass ") + ClassName + TEXT(" : public TLBaseObject"));
	sb.WriteLine(TEXT("{"));
	sb.WriteLine(TEXT("public:"));
// 	sb.WriteLine("\tvirtual void OnSend(BinaryWriter writer) ");
// 	sb.WriteLine("\t{\n\n\t}\n");
// 	sb.WriteLine("\tvirtual void OnResponce(BinaryReader reader) ");
// 	sb.WriteLine("\t{\n\n\t}\n");
	sb.WriteLine(TEXT("};"));

	sb.WriteLine(TEXT("\n}"));

	FString FileName = FPaths::Combine(FilePath, ClassName) + TEXT(".h");
	FFileHelper::SaveStringToFile(sb.ReturnGeneratedCode(), *FileName);
}

void TLGenerator::WriteOnSendCode(TLSourceBuilder& sb, TLArg Arg, TArray<TLArg> Args, FString Name /*= ""*/)
{
	if (Name == TEXT(""))
		Name = TEXT("this->")+ Arg.Name();

	auto Type = Arg.Type();

	if (Arg.Type().Contains("TArray"))
		_LOG("");

	FRegexPattern Pattern(TEXT("TArray<([\\w[\\s|^\\s](\\:\\:)?\\*?]+)"));
	FRegexMatcher Match(Pattern, Arg.Type());

	if (Match.FindNext())
	{
		Type = Match.GetCaptureGroup(1);
	}

	if (Arg.IsFlag())
	{
		if (Type == TEXT("true"))
		{
			return;
		}
		else
		{
			if (Type.Contains(TEXT("FString")))
				_LOG("")//sb.WriteLine(TEXT("\tif(!") + Name + TEXT(".IsEmpty())\n\t{"));
			else if (Arg.IsBytes() || Arg.IsVector())
				sb.WriteLine(TEXT("\tif(") + Name + TEXT(".Num())\n\t{"));
			else if (Type.Contains(TEXT("FDateTime")))
				sb.WriteLine(TEXT("\tif(") + Arg.Name() + TEXT(" == FDateTime::MinValue())\n\t{"));
			else
				sb.WriteLine(TEXT("\tif(") + Name + TEXT(")\n\t{"));
		}
			//sb.WriteLine(TEXT("\tif(!") + Name + TEXT(")\n\t{"));
	}

	if (Arg.IsVector())
	{
		if (Arg.IsUsingVectorID())
			sb.WriteLine(TEXT("\tWriter.WriteInt(0x1cb5c415);"));
		sb.WriteLine(TEXT("\tWriter.WriteInt(") + Name + TEXT(".Num());"));
		sb.WriteLine(TEXT("\tfor(auto X : ") + Name + TEXT(")"));
		sb.WriteLine(TEXT("\t{"));
		Arg.IsVector(false);
		this->WriteOnSendCode(sb, Arg, Args, TEXT("X"));
		Arg.IsVector(true);
	}

	else if (Arg.IsFlagIndicator())
	{
		sb.WriteLine(TEXT("\t//Calculate the flags. This equals to those flag arguments which are NOT None"));
		sb.WriteLine(TEXT("\tint32 Flags = 0;"));
		for (auto Flag : Args)
		{
			
			auto FlagType = Flag.Type();

			if (Flag.Type().Contains("TArray"))
				_LOG("");

			FRegexPattern Pattern(TEXT("TArray<([\\w[\\s|^\\s](\\:\\:)?\\*?]+)"));
			FRegexMatcher Match(Pattern, Flag.Type());

			if (Match.FindNext())
			{
				FlagType = Match.GetCaptureGroup(1);
			}

			if (Flag.IsFlag())
			{
				if (FlagType == TEXT("FString"))
					sb.WriteLine(TEXT("\tif(!") + Flag.Name() + TEXT(".IsEmpty())\n\t{"));
				else if (Flag.IsBytes() || Flag.IsVector())
					sb.WriteLine(TEXT("\tif(") + Flag.Name() + TEXT(".Num())\n\t{"));
				else if (FlagType == TEXT("FDateTime"))
					sb.WriteLine(TEXT("\tif(") + Flag.Name() + TEXT(" == FDateTime::MinValue())\n\t{"));
				else
					sb.WriteLine(TEXT("\tif(") + Flag.Name() + TEXT(")\n\t{"));
				sb.WriteLine(FString::Printf__VA(TEXT("\t\tFlags |= (1 << %d);"), Flag.FlagIndex()));
				sb.WriteLine(TEXT("\t}"));
				sb.WriteLine(TEXT("\telse"));
				sb.WriteLine(TEXT("\t{"));
				sb.WriteLine(TEXT("\t\tFlags |= 0;"));
				sb.WriteLine(TEXT("\t}"));
			}
		}
		sb.WriteLine(TEXT("\tWriter.WriteInt(Flags);"));
		sb.WriteLine(TEXT(""));
	}

	else if(Arg.IsBytes())
		sb.WriteLine(TEXT("\tWriter.TGWriteBytes((unsigned char*)") + Name + TEXT(".GetData(), ") + Name + TEXT(".Num());"));

	else if (Type == TEXT("int32"))
		sb.WriteLine(TEXT("\tWriter.WriteInt(") + Name + TEXT(");"));

	else if (Type == TEXT("double"))
		sb.WriteLine(TEXT("\tWriter.WriteDouble(") + Name + TEXT(");"));

	else if (Type == TEXT("unsigned long long"))
		sb.WriteLine(TEXT("\tWriter.WriteLong(") + Name + TEXT(");"));

	else if (Type == TEXT("TBigInt<128>"))
		sb.WriteLine(TEXT("\tWriter.Write128Int(") + Name + TEXT(");"));

	else if (Type == TEXT("TBigInt<256>"))
		sb.WriteLine(TEXT("\tWriter.Write256Int(") + Name + TEXT(");"));

	else if (Type == TEXT("FString"))
		sb.WriteLine(TEXT("\tWriter.TGWriteString(") + Name + TEXT(");"));

	else if (Type == TEXT("bool"))
		sb.WriteLine(TEXT("\tWriter.WriteBool(") + Name + TEXT(");"));

	else if (Type == TEXT("true"))
		return;

	else if (Type == TEXT("FDateTime"))
		sb.WriteLine(TEXT("\tWriter.TGWriteDate(") + Name + TEXT(");"));

	else
		sb.WriteLine(TEXT("\t") + Name + TEXT("->OnSend(Writer);"));

	if (Arg.IsVector())
		sb.WriteLine(TEXT("\t}"));
	if (Arg.IsFlag())
	{
		if (!Type.Contains(TEXT("FString")))
			sb.WriteLine(TEXT("\t}"));
	}
		
}

void TLGenerator::WriteOnResponceCode(TLSourceBuilder& sb, TLObject tl, TLArg Arg, TArray<TLArg> Args, TArray<FString> AbstractClasses, TArray<FString> CommonClasses, FString Name /*= TEXT("")*/)
{
	if (Name.IsEmpty())
		Name = Arg.Name();
	else
		Name = "auto " + Name;

	auto Type = Arg.Type();

	if (Arg.Type().Contains("TArray"))
		_LOG("");

	FRegexPattern Pattern(TEXT("TArray<([\\w[\\s|^\\s](\\:\\:)?\\*?]+)"));
	FRegexMatcher Match(Pattern, Arg.Type());

	if (Match.FindNext())
	{
		Type = Match.GetCaptureGroup(1);
	}

	bool WasFlag = false;
	if (Arg.IsFlag())
	{
		WasFlag = true;
		sb.WriteLine(FString::Printf__VA(TEXT("\tif((Flags & (1 << %d)) != 0) \n\t{"), Arg.FlagIndex()));
		Arg.IsFlag(false);
	}

	if (Arg.IsVector())
	{
		if (Arg.IsUsingVectorID())
			sb.WriteLine(TEXT("\tReader.ReadInt();"));
		sb.WriteLine(TEXT("\n\t//Len concatenated with rand number to get rid of confusions with redefinition"));
		int32 Rand = FMath::Rand();
		sb.WriteLine(TEXT("\tint32 Len") + FString::FromInt(Rand) + TEXT(" = Reader.ReadInt();"));
		sb.WriteLine(TEXT("\tfor(int32 i = 0; i < Len") + FString::FromInt(Rand) + TEXT("; i++)"));
		sb.WriteLine(TEXT("\t{"));
		Arg.IsVector(false);
		this->WriteOnResponceCode(sb, tl, Arg, Args, AbstractClasses, CommonClasses, TEXT("X"));
		sb.WriteLine(TEXT("\t") + Name + TEXT(".Add(X);"));
		Arg.IsVector(true);
	}

	else if (Arg.IsFlagIndicator())
	{
		sb.WriteLine(TEXT("\tauto Flags = Reader.ReadInt();"));
		sb.WriteLine(TEXT(""));
	}

	else if (Arg.IsBytes())
		sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.TGReadBytes();"));

	else if (Type == TEXT("int32"))
		sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.ReadInt();"));

	else if (Type == TEXT("double"))
		sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.ReadDouble();"));

	else if (Type == TEXT("unsigned long long"))
		sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.ReadLong();"));

	else if (Type == TEXT("TBigInt<128>"))
		sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.Read128Int();"));

	else if (Type == TEXT("TBigInt<256>"))
		sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.Read256Int();"));

	else if (Type == TEXT("FString"))
		sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.TGReadString();"));

	else if (Type == TEXT("bool"))
		sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.ReadBool();"));

	else if (Type == TEXT("true"))
		sb.WriteLine(TEXT("\t\t") + Name + TEXT(" = true;"));

	else if (Type == TEXT("FDateTime"))
		sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.TGReadDate();"));

	else
	{
		FString _Namespace;

		if (Type.Contains(TEXT("::")))
			Type.Split(TEXT("::"), &_Namespace, &Type);

		if (AbstractClasses.Contains(Type) && !Arg.IsVector())
		{
			sb.WriteLine(TEXT("\t") + Name + TEXT(" = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());"));
		}

		else if (!AbstractClasses.Contains(Type) && !Arg.SystemTypes().Contains(Type) && !Arg.IsVector() && !Arg.IsBytes())
		{
			if (CommonClasses.Contains(Type) && _Namespace.IsEmpty())
			{
				sb.WriteLine(TEXT("\t") + Name + TEXT(" = reinterpret_cast<") + Type + TEXT(">(Reader.TGReadObject());"));
			}
			else if(!_Namespace.IsEmpty())
			{
				sb.WriteLine(TEXT("\t") + Name + TEXT(" = reinterpret_cast<") + _Namespace + TEXT("::") + Type + TEXT(">(Reader.TGReadObject());"));
			}
			else
			{
				sb.WriteLine(TEXT("\t") + Name + TEXT(" = reinterpret_cast<") + Type + TEXT(">(Reader.TGReadObject());"));
			}
		}
	}

	if (Arg.IsVector())
		sb.WriteLine(TEXT("\t}"));

	if (WasFlag)
	{
		sb.WriteLine(TEXT("\t}"));
		Arg.IsFlag(true);
	}
}

void TLGenerator::WriteRequestResultCode(TLSourceBuilder& sb, TLObject tl)
{
	if (tl.Result().Contains(FString(TEXT("TArray"))))
	{
		if (tl.Result().Contains(TEXT("TArray<int32>")))
		{
			sb.WriteLine(TEXT("\tReader.ReadInt();"));
			sb.WriteLine(TEXT("\tint32 Count = Reader.ReadInt();"));
			sb.WriteLine(TEXT("\tfor(int32 i = 0; i < Count; i++)"));
			sb.WriteLine(TEXT("\t{"));
			sb.WriteLine(TEXT("\t\tthis->result.Add(Reader.ReadInt());"));
			sb.WriteLine(TEXT("\t}"));
		}

		else if (tl.Result().Contains(TEXT("TArray<unsigned long long>")))
		{
			sb.WriteLine(TEXT("\tReader.ReadInt();"));
			sb.WriteLine(TEXT("\tint32 Count = Reader.ReadLong();"));
			sb.WriteLine(TEXT("\tfor(int32 i = 0; i < Count; i++)"));
			sb.WriteLine(TEXT("\t{"));
			sb.WriteLine(TEXT("\t\tthis->result.Add(Reader.ReadLong());"));
			sb.WriteLine(TEXT("\t}"));
		}

		else
		{
			FRegexPattern Pattern(TEXT("TArray<(\\w+)>"));
			FRegexMatcher Match(Pattern, tl.Result());

			if (Match.FindNext())
			{
				FString Type = Match.GetCaptureGroup(1);
				sb.WriteLine(TEXT("\tif(0x1cb5c415 == Reader.ReadInt())\n\t{"));
				sb.WriteLine(TEXT("\t\tint32 Count = Reader.ReadInt();"));
				sb.WriteLine(TEXT("\t\tfor(int32 i = 0; i < Count; i++)\n\t{"));
				sb.WriteLine(TEXT("\t\t\tthis->result.Add(reinterpret_cast<") + Type + TEXT(">(Reader.TGReadObject()));"));
				sb.WriteLine(TEXT("\t\t}"));
				sb.WriteLine(TEXT("\t}"));
			}
		}
	}
	else if (tl.Result() == TEXT("bool"))
	{
		sb.WriteLine(TEXT("\t\tthis->result = Reader.ReadBool();"));
	}
	else
	{
		sb.WriteLine(TEXT("\tthis->result = reinterpret_cast<")+ tl.Result() + TEXT(">(Reader.TGReadObject());"));
		//sb.WriteLine("}");
	}
}
