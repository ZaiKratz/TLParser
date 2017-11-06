#include "Generator.h"
#include "crc.h"
#include "PlatformFilemanager.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "FileHelper.h"
#include "TlParser.h"
#include "SourceBuilder.h"
#include "Regex.h"
#include "FileManager.h"

#include "../Source/Parser/TL/TLObjectBase.h"


FString CamalCase(FString ClassName)
{
	FRegexPattern Pattern("");
	if (ClassName.Contains(TEXT("_")))
		Pattern = FRegexPattern(
			TEXT("((?i)[a-z]+\\d?)_*")
		);
	else
		Pattern = FRegexPattern(
			TEXT("((?i)[a-z]+\\d?)")
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

// Delete all TLObjects
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


void TLGenerator::GenerateTLObjects(FString SchemeFile)
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
			auto Type = tl.Result();

			FRegexPattern TypePattern(TEXT("TArray<([\\w[\\:\\:]?]+)>"));
			FRegexMatcher TypeMatch(TypePattern, Type);

			FString _Name;
			FString _Namespace;
			if (Type.Contains(TEXT("::")))
			{
				Type.Split("::", &_Namespace, &_Name);
				if (!AllNames.Contains(_Name) && !TypeMatch.FindNext() &&
					!_Name.Contains(TEXT("TLBaseObject")) && _Name != ("bool") && !tl.SystemTypes.Contains(_Name))
					AbstractTypes.AddUnique(_Name);
			}
			else if (!AllNames.Contains(Type) && !TypeMatch.FindNext() && !Type.Contains(TEXT("TLBaseObject")) &&
				Type != ("bool") && !tl.SystemTypes.Contains(Type))
				AbstractTypes.AddUnique(Type);
		}
		

		WriteAllObjects(TLObjects, FuncDir, TypesDir, PlatformFile, AbstractTypes, CommonNames, SchemeFile, PluginContentDir);

	}
}


void TLGenerator::WriteAllObjects(TArray<TLObject> TLObjects, FString FuncDir, FString TypesDir, IPlatformFile &PlatformFile, TArray<FString> AbstractTypes, TArray<FString> CommonNames, FString SchemeFile, FString PluginContentDir)
{
	TLSourceBuilder sb;
	sb.WriteLine(TEXT("#pragma once"));
	sb.WriteLine(TEXT("#include \"Engine.h\""));

	for (auto tl : TLObjects)
	{
		Args.Empty();
		if (tl.Name().IsEmpty() && tl.Namespace().IsEmpty())
			continue;

		if (tl.IsFunction())
			this->_OutputDir = FuncDir;
		else
			this->_OutputDir = TypesDir;

		this->_OutputDir = FPaths::Combine(this->_OutputDir, tl.Namespace());
		if (!PlatformFile.DirectoryExists(*this->_OutputDir))
		{
			PlatformFile.CreateDirectory(*this->_OutputDir);
			PlatformFile.CreateDirectory(*(FPaths::Combine(this->_OutputDir, FString(TEXT("Private")))));
			PlatformFile.CreateDirectory(*(FPaths::Combine(this->_OutputDir, FString(TEXT("Public")))));
		}

		auto HeaderFilePath = FPaths::Combine(this->_OutputDir, FString(TEXT("Public")));
		this->WriteHeaderCode(HeaderFilePath, tl, AbstractTypes, CommonNames);

		auto SourceFilePath = FPaths::Combine(this->_OutputDir, FString(TEXT("Private")));
		this->WriteSourceCode(SourceFilePath, tl, AbstractTypes, CommonNames);

		if (tl.IsFunction())
			sb.WriteLine(TEXT("#include \"Functions/") + tl.Namespace() + TEXT("/Public/") + tl.Name() + TEXT(".h\""));
		else
			sb.WriteLine(TEXT("#include \"Types/") + tl.Namespace() + TEXT("/Public/") + tl.Name() + TEXT(".h\""));
	}

	sb.WriteLine(TEXT("\n"));
	sb.WriteLine(TEXT("TLBaseObject* TLObjects(uint32 ConstructorID)"));
	sb.WriteLine(TEXT("{"));
	sb.WriteLine(TEXT("\tswitch(ConstructorID)"));
	sb.WriteLine(TEXT("\t{"));
	for (auto tl : TLObjects)
	{
		sb.WriteLine(TEXT("\t\tcase ") + FString::Printf(TEXT("%u"), tl.ID()) + TEXT(": "));
		sb.WriteLine(TEXT("\t\t{"));
		sb.WriteLine(TEXT("\t\t\treturn new ") + tl.Namespace() + TEXT("::") + tl.Name() + TEXT("();"));
		sb.WriteLine(TEXT("\t\tbreak;"));
		sb.WriteLine(TEXT("\t\t}"));
	}
	sb.WriteLine(TEXT("\t\tdefault: "));
	sb.WriteLine(TEXT("\t\t\treturn nullptr; "));
	sb.WriteLine(TEXT("\t}"));
	sb.WriteLine(TEXT("}"));

	int32 CurrentLayer = TLParser::FindLayer(SchemeFile);
	sb.WriteLine(TEXT("int32 CurrentLayer()"));
	sb.WriteLine(TEXT("{"));
	sb.WriteLine(TEXT("\treturn ") + FString::FromInt(CurrentLayer) + TEXT(";"));
	sb.WriteLine(TEXT("}"));

	auto FilePath = FPaths::Combine(PluginContentDir, FString(TEXT("AllObjects.h")));
	if (PlatformFile.FileExists(*FilePath))
		PlatformFile.DeleteFile(*FilePath);
	FFileHelper::SaveStringToFile(sb.ReturnGeneratedCode(), *FilePath);
}

void TLGenerator::WriteHeaderCode(FString HeaderFilePath, TLObject& tl, TArray<FString> AbstractClasses, TArray<FString> CommonClasses)
{
	FString UsingDepth = TEXT("../../");

	FString FileName = FPaths::Combine(HeaderFilePath, tl.Name()) + TEXT(".h");

	FString HeaderCode;

	FString Namespaces;

	FString TLName = tl.Name();
	FString TLNamespace = tl.Namespace();

	TLSourceBuilder sb;

	TArray<FString> CompareTypes;

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

			if (Arg.SystemTypes.Contains(Arg.Name()))
			{
				auto Tmp = Arg.Name();
				Tmp[0] = toupper(Tmp[0]);
				Arg.SetName(Tmp);
			}
			
			if(!Arg.SystemTypes.Contains(Arg.Type()))
			{
				Type[0] = toupper(Type[0]);
			}

			if (AbstractClasses.Contains(Type) && !Arg.IsVector())
			{
				Args += /*TEXT("PRIVATE::") + Type +*/ TEXT("TLBaseObject* ") + Arg.Name();
				Arg.SetType(/*TEXT("PRIVATE::") + Arg.Type() + */TEXT("TSharedPtr<TLBaseObject> "));
// 				if (!CompareTypes.Contains(Type))
// 					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Private/") + Type + TEXT(".h\"");
			}
			else if (Arg.Type() == TEXT("TLBaseObject"))
			{
				Args += TEXT("TLBaseObject* ") + Arg.Name();
				Arg.SetType(TEXT("TSharedPtr<TLBaseObject> "));
			}
			else if (Arg.IsBytes())
			{
				Args += TEXT("const TArray<") + Type + TEXT(">& ") + Arg.Name();
				Arg.SetType(TEXT("TArray<") + Type + TEXT("> "));
			}
			else if (Type == TEXT("FDateTime"))
			{
				Args += TEXT("const ") + Type + "& " + Arg.Name();
			}
			else if (Arg.IsVector() && AbstractClasses.Contains(Type))
			{
				Args += TEXT("const TArray<TLBaseObject>& ") + Arg.Name();
				Arg.SetType(TEXT("TArray<TLBaseObject> "));
				//Args += TEXT("TArray<PRIVATE::") + Type + TEXT("*> ") + Arg.Name();
				//Arg.SetType(TEXT("TArray<PRIVATE::") + Type + TEXT("*> "));
// 				if (!CompareTypes.Contains(Type))
// 					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Private/") + Type + TEXT(".h\"");
			}
			else if (Arg.IsVector() && !AbstractClasses.Contains(Type))
			{
				if (!Arg.SystemTypes.Contains(Type))
				{
					if (CommonClasses.Contains(Type) && _Namespace.IsEmpty())
					{
						Args += TEXT("const TArray<COMMON::") + Type + TEXT(">& ") + Arg.Name();
						Arg.SetType(TEXT("TArray<COMMON::") + Type + TEXT("> "));
						if (!CompareTypes.Contains(Type))
							Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Common/Public/") + Type + TEXT(".h\"");
					}
					else
					{
						Args += TEXT("const TArray<") + _Namespace + TEXT("::") + Type + TEXT(">& ") + Arg.Name();
						Arg.SetType(TEXT("TArray<") + _Namespace + TEXT("::") + Type + TEXT("> "));
						if (!CompareTypes.Contains(Type))
							Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/") + _Namespace + ("/Public/") + Type + TEXT(".h\"");
					}
					//Arg.Type(TEXT("TArray<COMMON::") + Type + TEXT("> "));

				}
				else
				{
					Args += TEXT("const TArray<") + Type + TEXT(">& ") + Arg.Name();
					Arg.SetType(TEXT("TArray<") + Type + TEXT("> "));
				}
			}
			else if (Arg.Type() == TEXT("true") || Type.Contains(TEXT("bool")))
			{
				Args += TEXT("bool ") + Arg.Name();
				Arg.SetType(TEXT("bool"));
			}
			else if (!AbstractClasses.Contains(Type) && !Arg.SystemTypes.Contains(Type) && !Arg.IsVector() && !Arg.IsBytes())
			{
				if (CommonClasses.Contains(Type) && _Namespace.IsEmpty())
				{
					Args += TEXT("COMMON::") + Type + TEXT("* ") + Arg.Name();
					Arg.SetType(TEXT("TSharedPtr<COMMON::") + Type + TEXT("> "));
					if (!CompareTypes.Contains(Type))
						Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Common/Public/") + Type + TEXT(".h\"");
				}
				else
				{
					Args += _Namespace + TEXT("::") + Type + TEXT("* ") + Arg.Name();
					Arg.SetType(TEXT("TSharedPtr<") + _Namespace + TEXT("::") + Type + TEXT("> "));
					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/") + _Namespace + ("/Public/") + Type + TEXT(".h\"");
				}
				//Arg.Type(TEXT("COMMON::") + Arg.Type());

			}
			else if (Arg.SystemTypes.Contains(Type) && !Arg.IsBytes())
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

	if (!tl.SystemTypes.Contains(tl.Result()))
	{
		if(tl.IsFunction())
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
					tl.SetResult(TEXT("TSharedPtr<TLBaseObject>"));
				}
				else
				{
					tl.SetResult(TEXT("TSharedPtr<") + TMPNamespace.ToUpper() + "::" + TMPName + TEXT(">"));
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
					tl.SetResult(TEXT("TSharedPtr<TLBaseObject>"));
				}
				else
				{
					if (tl.Result().Contains(TEXT("TArray<")))
					{
						FRegexPattern VectorPattern(TEXT("TArray<([\\w[\\s|^\\s](\\:\\:)?\\*?]+)>"));
						FRegexMatcher VectorMatch(VectorPattern, tl.Result());

						if (VectorMatch.FindNext())
							tl.SetResult(VectorMatch.GetCaptureGroup(1));

						if (AbstractClasses.Contains(tl.Result()))
						{
							// 						if (tl.Result() != tl.Name())
							// 							Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Private/") + tl.Result() + TEXT(".h\"");
							tl.SetResult(TEXT("TArray<TLBaseObject>"));
						}
						else if (CommonClasses.Contains(tl.Result()))
						{
							if (tl.Result() != tl.Name())
								Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Common/Public/") + tl.Result() + TEXT(".h\"");
							tl.SetResult(TEXT("TArray<COMMON::") + tl.Result() + TEXT(">"));
						}
						else if (tl.SystemTypes.Contains(tl.Result()))
							tl.SetResult(TEXT("TArray<") + tl.Result() + TEXT(">"));
						else
						{
							FString _Name;
							FString _Namespace;
							tl.Result().Split("::", &_Namespace, &_Name);
							if (tl.Result() != tl.Name())
								if (!_Namespace.IsEmpty())
									Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/") + _Namespace + TEXT("/Public/") + _Name + TEXT(".h\"");
							tl.SetResult(TEXT("TArray<") + tl.Result() + TEXT(">"));
						}


					}
					else
					{
						if (CommonClasses.Contains(tl.Result()))
						{
							if (tl.Result() != tl.Name())
								Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Common/Public/") + tl.Result() + TEXT(".h\"");
							tl.SetResult(TEXT("TSharedPtr<COMMON::") + tl.Result() + TEXT(">"));
						}
						else if (tl.SystemTypes.Contains(tl.Result()))
							tl.SetResult(TEXT("") + tl.Result() + TEXT(""));
						else
						{
							tl.SetResult(TEXT("TSharedPtr<") + tl.Result() + TEXT(">"));
						}
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
		sb.WriteLine(TEXT("namespace ") + TLNamespace);
		sb.WriteLine(TEXT("{"));
	}

	sb.WriteLine(TEXT("class ") + TLName + TEXT(" : public ") + InheritFrom + TEXT("\n{"));
	sb.WriteLine(TEXT("public:"));
	sb.WriteLine(TEXT("\t") + TLName + TEXT("();"));

	if (!Args.IsEmpty())
	{
		sb.WriteLine(TEXT("\t") + TLName + TEXT("(") + Args + TEXT(");"));

		sb.WriteLine(TEXT(""));

	}
	//sb.WriteLine(TEXT("\t~") + UpperName + TEXT("();"));

	sb.WriteLine(TEXT("\tvirtual void OnSend(BinaryWriter& Writer) override;"));
	sb.WriteLine(TEXT("\tvirtual void OnResponce(BinaryReader& Reader) override;"));
	sb.WriteLine(TEXT(""));

	for (auto Arg : tl.Args())
	{
		if(!Arg.IsFlagIndicator())
		{
			FString ArgName;
			ArgName = CamalCase(Arg.Name());

			if (Arg.IsTrueType() || Arg.Type().Contains(TEXT("bool")))
			{
				sb.WriteLine(TEXT("\tbool Get") + ArgName + TEXT("() const")); 
				sb.WriteLine(TEXT("\t{"));
				sb.WriteLine(TEXT("\t\t return this->") + Arg.Name() + TEXT(";"));
				sb.WriteLine(TEXT("\t}\n"));
			}
			else
			{
				if(Arg.Type().Contains(TEXT("TSharedPtr")))
				{
					FRegexPattern SharedPtrPattern(TEXT("TSharedPtr<([\\w[\\s|^\\s](\\:\\:)?\\*?]+)>"));
					FRegexMatcher SharedPtrMatch(SharedPtrPattern, Arg.Type());
					if (SharedPtrMatch.FindNext())
					{
						sb.WriteLine(TEXT("\t") + SharedPtrMatch.GetCaptureGroup(1) + TEXT("* Get") + ArgName + TEXT("() const")); sb.WriteLine(TEXT("\t{"));
						sb.WriteLine(TEXT("\t\t return this->") + Arg.Name() + TEXT(".Get();"));
						sb.WriteLine(TEXT("\t}\n"));
					}
				}
				else
				{
					sb.WriteLine(TEXT("\t") + Arg.Type() + TEXT(" Get") + ArgName + TEXT("() const")); sb.WriteLine(TEXT("\t{"));
					sb.WriteLine(TEXT("\t\t return this->") + Arg.Name() + TEXT(";"));
					sb.WriteLine(TEXT("\t}\n"));
				}
			}
			
		}
	}
	

	if (tl.IsFunction())
	{
		if (tl.Result() == TEXT("true") || tl.Result().Contains(TEXT("bool")))
		{
			sb.WriteLine(TEXT("\tbool GetResult() const"));
			sb.WriteLine(TEXT("\t{"));
			sb.WriteLine(TEXT("\t\t return this->result;"));
			sb.WriteLine(TEXT("\t}\n"));
		}
		else
		{
			if (tl.Result().Contains(TEXT("TSharedPtr")))
			{
				FRegexPattern SharedPtrPattern(TEXT("TSharedPtr<([\\w[\\s|^\\s](\\:\\:)?\\*?]+)>"));
				FRegexMatcher SharedPtrMatch(SharedPtrPattern, tl.Result());

				if (SharedPtrMatch.FindNext())
				{
					sb.WriteLine(TEXT("\t") + SharedPtrMatch.GetCaptureGroup(1) + TEXT("* GetResult() const"));
					sb.WriteLine(TEXT("\t{"));
					sb.WriteLine(TEXT("\t\t return this->result.Get();"));
					sb.WriteLine(TEXT("\t}\n"));
				}
			}
			else
			{
				sb.WriteLine(TEXT("\t") + tl.Result() + TEXT(" GetResult() const"));
				sb.WriteLine(TEXT("\t{"));
				sb.WriteLine(TEXT("\t\t return this->result;"));
				sb.WriteLine(TEXT("\t}\n"));
			}
		}
		
	}

	sb.WriteLine(TEXT("private:"));
	
// 	if (!Args.IsEmpty())
// 	{
// 		TArray<FString> SplitArgs;
// 		Args.ParseIntoArray(SplitArgs, TEXT(","));
// 
// 		for (auto Line : SplitArgs)
// 		{
// 			sb.WriteLine(TEXT("\t") + Line + TEXT(";"));
// 		}
// 	}

	if (tl.Args().Num())
	{
		for (auto Arg : tl.Args())
		{
			if(!Arg.IsFlagIndicator())
				sb.WriteLine(TEXT("\t") + Arg.Type() + TEXT(" ") + Arg.Name() + TEXT(";"));
		}
	}

	if (tl.IsFunction())
	{
		if (tl.Result() == TEXT("true"))
			sb.WriteLine(TEXT("\tbool result;"));
		else
		{
			sb.WriteLine(TEXT("\t") + tl.Result() + TEXT(" result;"));
		}
	}

	sb.WriteLine(TEXT("};"));

	if (!tl.Namespace().IsEmpty())
	{
		sb.WriteLine(TEXT("} //end namespace block"));
	}

	HeaderCode = sb.ReturnGeneratedCode();

	FFileHelper::SaveStringToFile(HeaderCode, *FileName);
}

void TLGenerator::WriteSourceCode(FString SourceFilePath, TLObject& tl, TArray<FString> AbstractClasses, TArray<FString> CommonClasses)
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
	sb.WriteLine(FString::Printf__VA(TEXT("\tthis->_ConstructorID = %u;"), tl.ID()));
	if (tl.IsFunction())
		sb.WriteLine(TEXT("\tthis->_ContentRelated = true;"));
	for (auto Arg : tl.Args())
	{
		if (Arg.IsTrueType() || Arg.Type().Contains(TEXT("bool")))
			sb.WriteLine(TEXT("\tthis->") + Arg.Name() + TEXT(" = false;"));
		else
			if (Arg.SystemTypes.Contains(Arg.Type()) && !Arg.IsVector() && !Arg.Type().Contains(TEXT("TBigInt"))
				&& !Arg.Type().Contains(TEXT("FString")) && !Arg.Type().Contains(TEXT("FDateTime")))
				sb.WriteLine(TEXT("\tthis->") + Arg.Name() + TEXT(" = 0;"));
	}
	sb.WriteLine(TEXT("}"));

	//Detecting arguments

// 	FString Args;
// 	
// 
// 	if (tl.Args().Num())
// 	{
// 		for (auto &Arg : tl.Args())
// 		{
// 			if (Arg.Type().IsEmpty())
// 				continue;
// 
// 			auto Type = Arg.Type();
// 			FString _Namespace;
// 
// 
// 			if (Type.Contains("::"))
// 			{
// 				Type.Split("::", &_Namespace, &Type);
// 				_Namespace.ToUpperInline();
// 				Type[0] = toupper(Type[0]);
// 			}
// 
// 			if (Arg.SystemTypes.Contains(Arg.Name()))
// 			{
// 				auto Tmp = Arg.Name();
// 				Tmp[0] = toupper(Tmp[0]);
// 				Arg.SetName(Tmp);
// 			}
// 
// 			if (!Arg.SystemTypes.Contains(Arg.Type()))
// 			{
// 				Type[0] = toupper(Type[0]);
// 			}
// 
// 			if (AbstractClasses.Contains(Type) && !Arg.IsVector())
// 			{
// 				Args += /*TEXT("PRIVATE::") + Type +*/ TEXT("TLBaseObject* ") + Arg.Name();
// 				//Arg.SetType(/*TEXT("PRIVATE::") + Arg.Type() + */TEXT("TLBaseObject* "));
// 				// 				if (!CompareTypes.Contains(Type))
// 				// 					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Private/") + Type + TEXT(".h\"");
// 			}
// 			else if (Arg.Type() == TEXT("TLBaseObject"))
// 			{
// 				Args += Type + TEXT("* ") + Arg.Name();
// 				//Arg.SetType(Arg.Type() + TEXT("* "));
// 			}
// 			else if (Arg.IsBytes())
// 			{
// 				Args += TEXT("TArray<") + Type + TEXT("> ") + Arg.Name();
// 				//Arg.SetType(TEXT("TArray<") + Type + TEXT("> "));
// 			}
// 			else if (Type == TEXT("FDateTime"))
// 			{
// 				Args += Type + " " + Arg.Name();
// 			}
// 			else if (Arg.IsVector() && AbstractClasses.Contains(Type))
// 			{
// 				Args += TEXT("TArray<TLBaseObject*> ") + Arg.Name();
// 				//Arg.SetType(TEXT("TArray<TLBaseObject*> "));
// 				//Args += TEXT("TArray<PRIVATE::") + Type + TEXT("*> ") + Arg.Name();
// 				//Arg.SetType(TEXT("TArray<PRIVATE::") + Type + TEXT("*> "));
// 				// 				if (!CompareTypes.Contains(Type))
// 				// 					Namespaces += TEXT("\n#include \"") + UsingDepth + TEXT("Types/Private/") + Type + TEXT(".h\"");
// 			}
// 			else if (Arg.IsVector() && !AbstractClasses.Contains(Type))
// 			{
// 				if (!Arg.SystemTypes.Contains(Type))
// 				{
// 					if (CommonClasses.Contains(Type) && _Namespace.IsEmpty())
// 					{
// 						Args += TEXT("TArray<COMMON::") + Type + TEXT("*> ") + Arg.Name();
// 						//Arg.SetType(TEXT("TArray<COMMON::") + Type + TEXT("*> "));
// 					}
// 					else
// 					{
// 						Args += TEXT("TArray<") + _Namespace + TEXT("::") + Type + TEXT("*> ") + Arg.Name();
// 						//Arg.SetType(TEXT("TArray<") + _Namespace + TEXT("::") + Type + TEXT("*> "));
// 					}
// 					//Arg.Type(TEXT("TArray<COMMON::") + Type + TEXT("> "));
// 
// 				}
// 				else
// 				{
// 					Args += TEXT("TArray<") + Type + TEXT("> ") + Arg.Name();
// 					//Arg.SetType(TEXT("TArray<") + Type + TEXT("> "));
// 				}
// 			}
// 			else if (Arg.Type() == TEXT("true") || Type.Contains(TEXT("bool")))
// 			{
// 				Args += TEXT("bool ") + Arg.Name();
// 				//Arg.SetType(TEXT("bool"));
// 			}
// 			else if (!AbstractClasses.Contains(Type) && !Arg.SystemTypes.Contains(Type) && !Arg.IsVector() && !Arg.IsBytes())
// 			{
// 				if (CommonClasses.Contains(Type) && _Namespace.IsEmpty())
// 				{
// 					Args += TEXT("COMMON::") + Type + TEXT("* ") + Arg.Name();
// 					//Arg.SetType(TEXT("COMMON::") + Type + TEXT("* "));
// 				}
// 				else
// 				{
// 					Args += _Namespace + TEXT("::") + Type + TEXT("* ") + Arg.Name();
// 					//Arg.SetType(_Namespace + TEXT("::") + Type + TEXT("* "));
// 				}
// 				//Arg.Type(TEXT("COMMON::") + Arg.Type());
// 
// 			}
// 			else if (Arg.SystemTypes.Contains(Type) && !Arg.IsBytes())
// 			{
// 				if (Arg.Type() == TEXT("TBigInt<256>") || Arg.Type() == TEXT("TBigInt<128>"))
// 				Args += Type + TEXT(" ") + Arg.Name();
// 			}
// 
// 			Args += TEXT(", ");
// 		}
// 	}
// 
// 	Args.RemoveFromEnd(TEXT(", "));

	//Constructor with parameters generation 
	if (tl.Args().Num())
	{
		sb.WriteLine(TEXT("\n") + UpperName + TEXT("::") + UpperName + TEXT("(") + Args + TEXT(")"));
		sb.WriteLine(TEXT("{"));
		sb.WriteLine(FString::Printf__VA(TEXT("\tthis->_ConstructorID = %u;"), tl.ID()));
		if (tl.IsFunction())
			sb.WriteLine(TEXT("\tthis->_ContentRelated = true;"));
		for (auto Arg : tl.Args())
		{
			if (!Arg.IsFlagIndicator())
			{
				if(Arg.Type().Contains(TEXT("TSharedPtr")))
				{
					FRegexPattern SharedPtrPattern(TEXT("TSharedPtr<([\\w[\\s|^\\s](\\:\\:)?\\*?]+)>"));
					FRegexMatcher SharedPtrMatch(SharedPtrPattern, Arg.Type());

					if (SharedPtrMatch.FindNext())
						sb.WriteLine(TEXT("\tthis->") + Arg.Name() + TEXT(" = MakeShareable(") + Arg.Name() + TEXT(");"));
				}
				else
					sb.WriteLine(TEXT("\tthis->") + Arg.Name() + TEXT(" = ") + Arg.Name() + TEXT(";"));
			}
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
// 	sb.WriteLine(UpperName + TEXT("::~") + UpperName + TEXT("()"));
// 	sb.WriteLine(TEXT("{"));
// 
// 	for (auto Arg : tl.Args())
// 	{
// 		if (!Arg.IsVector() && !Arg.IsBytes() && !Arg.SystemTypes.Contains(Arg.Type()) && Arg.Type().Contains(TEXT("*")))
// 		{
// 			sb.WriteLine(TEXT("\tif(this->" + Arg.Name() + ")"));
// 			sb.WriteLine(TEXT("\t{"));
// 			sb.WriteLine(TEXT("\t\tdelete this->" + Arg.Name() + ";"));
// 			sb.WriteLine(TEXT("\t\tthis->" + Arg.Name() + " = nullptr;"));
// 			sb.WriteLine(TEXT("\t}"));
// 		}
// 
// 		if (Arg.IsVector() && Arg.Type().Contains(TEXT("*")))
// 		{
// 			sb.WriteLine(TEXT("\tfor(auto X : this->") + Arg.Name() + TEXT(")"));
// 			sb.WriteLine(TEXT("\t{"));
// 			sb.WriteLine(TEXT("\t\tif(X)"));
// 			sb.WriteLine(TEXT("\t\t{"));
// 			sb.WriteLine(TEXT("\t\t\tdelete X;"));
// 			sb.WriteLine(TEXT("\t\t\tX = nullptr;"));
// 			sb.WriteLine(TEXT("\t\t}"));
// 			sb.WriteLine(TEXT("\t}"));
// 		}
// 	}
// 
// 	if(tl.IsFunction())
// 	{
// 		if (!tl.Result().Contains(TEXT("TArray")) && !tl.SystemTypes.Contains(tl.Result()) && tl.Result().Contains(TEXT("*")))
// 		{
// 			sb.WriteLine(TEXT("\tif(this->result)"));
// 			sb.WriteLine(TEXT("\t{"));
// 			sb.WriteLine(TEXT("\t\tdelete this->result;"));
// 			sb.WriteLine(TEXT("\t\tthis->result = nullptr;"));
// 			sb.WriteLine(TEXT("\t}"));
// 		}
// 
// 		if (tl.Result().Contains(TEXT("TArray")) && !tl.SystemTypes.Contains(tl.Result()) && tl.Result().Contains(TEXT("*")))
// 		{
// 			sb.WriteLine(TEXT("\tfor(auto X : this->result)"));
// 			sb.WriteLine(TEXT("\t{"));
// 			sb.WriteLine(TEXT("\t\tif(X)"));
// 			sb.WriteLine(TEXT("\t\t{"));
// 			sb.WriteLine(TEXT("\t\t\tdelete X;"));
// 			sb.WriteLine(TEXT("\t\t\tX = nullptr;"));
// 			sb.WriteLine(TEXT("\t\t}"));
// 			sb.WriteLine(TEXT("\t}"));
// 		}
// 	}
// 
// 	
// 	
// 	sb.WriteLine(TEXT("}"));

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

void TLGenerator::WriteOnSendCode(TLSourceBuilder& sb, TLArg Arg, TArray<TLArg> Args, FString Name /*= TEXT("")*/, bool Pointer /*= true*/)
{
	if (Name == TEXT(""))
		Name = TEXT("this->")+ Arg.Name();

	FString Type = Arg.Type();

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
		if (Arg.IsTrueType())
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
				sb.WriteLine(TEXT("\tif(") + Name + TEXT(" == FDateTime::MinValue())\n\t{"));
			else if (Type.Contains(TEXT("TSharedPtr")) || !Arg.SystemTypes.Contains(Type))
				sb.WriteLine(TEXT("\tif(") + Name + TEXT(".IsValid())\n\t{"));
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
		this->WriteOnSendCode(sb, Arg, Args, TEXT("X"), false);
		Arg.IsVector(true);
	}

	else if (Arg.IsFlagIndicator())
	{
		sb.WriteLine(TEXT("\t//Calculate the flags. This equals to those flag arguments which are NOT None"));
		sb.WriteLine(TEXT("\tint32 Flags = 0;"));
		for (auto Flag : Args)
		{	
			auto FlagType = Flag.Type();

			FRegexPattern Pattern(TEXT("TArray<([\\w[\\s|^\\s](\\:\\:)?\\*?]+)"));
			FRegexMatcher Match(Pattern, FlagType);

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
				else if (FlagType.Contains(TEXT("TSharedPtr")) || !Flag.SystemTypes.Contains(FlagType))
					sb.WriteLine(TEXT("\tif(") + Flag.Name() + TEXT(".IsValid())\n\t{"));
				else if(Flag.SystemTypes.Contains(FlagType))
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
	{
		if(!Arg.IsTrueType())
			sb.WriteLine(TEXT("\tWriter.WriteBool(") + Name + TEXT(");"));
	}
		
	else if (Arg.IsTrueType())
		return;

	else if (Type == TEXT("FDateTime"))
		sb.WriteLine(TEXT("\tWriter.TGWriteDate(") + Name + TEXT(");"));

	else if (Arg.IsBytes())
		sb.WriteLine(TEXT("\tWriter.TGWriteBytes((unsigned char*)") + Name + TEXT(".GetData(), ") + Name + TEXT(".Num());"));

	else
		if(Pointer)
			sb.WriteLine(TEXT("\t") + Name + TEXT("->OnSend(Writer);"));
		else
			sb.WriteLine(TEXT("\t") + Name + TEXT(".OnSend(Writer);"));

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
		if(Arg.Type().Contains(TEXT("::")) || Arg.Type().Contains(TEXT("TLBaseObject")))
			sb.WriteLine(TEXT("\t") + Name + TEXT(".Add(*X);"));
		else
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
	{
		if (!Arg.IsTrueType())
			sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.ReadBool();"));
		else
			sb.WriteLine(TEXT("\t") + Name + TEXT(" = true;"));
	}
	else if (Arg.IsTrueType())
		sb.WriteLine(TEXT("\t\t") + Name + TEXT(" = true;"));

	else if (Type == TEXT("FDateTime"))
		sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.TGReadDate();"));

	else
	{
		FString _Namespace;

		if (Type.Contains(TEXT("TSharedPtr")))
		{
			FRegexPattern SharedPtrPattern(TEXT("TSharedPtr<([\\w[\\:\\:]?]+)>"));
			FRegexMatcher SharedPtrMatch(SharedPtrPattern, Arg.Type());
			if (SharedPtrMatch.FindNext())
				Type = SharedPtrMatch.GetCaptureGroup(1);
		}

		if (Type.Contains(TEXT("::")))
			Type.Split(TEXT("::"), &_Namespace, &Type);

		if (AbstractClasses.Contains(Type) && !Arg.IsVector())
		{
			//sb.WriteLine(TEXT("\tStaticObject = Reader.TGReadObject();"));
			if(Name != TEXT("auto X"))
				sb.WriteLine(TEXT("\t") + Name + TEXT(" = MakeShareable(Reader.TGReadObject());"));
			else
				sb.WriteLine(TEXT("\t") + Name + TEXT(" = Reader.TGReadObject();"));
		}

		else if (!AbstractClasses.Contains(Type) && !Arg.SystemTypes.Contains(Type) && !Arg.IsVector() && !Arg.IsBytes())
		{
			if (CommonClasses.Contains(Type) && _Namespace.IsEmpty())
			{		
				if (Name != TEXT("auto X"))
					sb.WriteLine(TEXT("\t") + Name + TEXT(" = MakeShareable(reinterpret_cast<") + Type + TEXT("*>(Reader.TGReadObject()));"));
				else
					sb.WriteLine(TEXT("\t") + Name + TEXT(" = reinterpret_cast<") + Type + TEXT("*>(Reader.TGReadObject());"));
			}
			else if(!_Namespace.IsEmpty())
			{
				if (Name != TEXT("auto X"))
					sb.WriteLine(TEXT("\t") + Name + TEXT(" = MakeShareable(reinterpret_cast<") + _Namespace + TEXT("::") + Type + TEXT("*>(Reader.TGReadObject()));"));
				else
					sb.WriteLine(TEXT("\t") + Name + TEXT(" = reinterpret_cast<") + _Namespace + TEXT("::") + Type + TEXT("*>(Reader.TGReadObject());"));
			}
			else
			{
				if (Name != TEXT("auto X"))
					sb.WriteLine(TEXT("\t") + Name + TEXT(" =  MakeShareable(reinterpret_cast<") + Type + TEXT("*>(Reader.TGReadObject()));"));
				else
					sb.WriteLine(TEXT("\t") + Name + TEXT(" = reinterpret_cast<") + Type + TEXT("*>(Reader.TGReadObject());"));
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
	FString Result = tl.Result();

	if (Result.Contains(TEXT("TSharedPtr")))
	{
		FRegexPattern SharedPtrPattern(TEXT("TSharedPtr<([\\w[\\s|^\\s](\\:\\:)?\\*?]+)>"));
		FRegexMatcher SharedPtrMatch(SharedPtrPattern, Result);
		if (SharedPtrMatch.FindNext())
			Result = SharedPtrMatch.GetCaptureGroup(1);
	}

	if (Result.Contains(FString(TEXT("TArray"))))
	{
		if (Result.Contains(TEXT("TArray<int32>")))
		{
			sb.WriteLine(TEXT("\tReader.ReadInt();"));
			sb.WriteLine(TEXT("\tint32 Count = Reader.ReadInt();"));
			sb.WriteLine(TEXT("\tfor(int32 i = 0; i < Count; i++)"));
			sb.WriteLine(TEXT("\t{"));
			sb.WriteLine(TEXT("\t\tthis->result.Add(Reader.ReadInt());"));
			sb.WriteLine(TEXT("\t}"));
		}

		else if (Result.Contains(TEXT("TArray<unsigned long long>")))
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
			FRegexPattern Pattern(TEXT("TArray<([\\w[\\s|^\\s](\\:\\:)?\\*?]+)>"));
			FRegexMatcher Match(Pattern, Result);

			if (Match.FindNext())
			{
				FString Type = Match.GetCaptureGroup(1);
				sb.WriteLine(TEXT("\tif(0x1cb5c415 == Reader.ReadInt())\n\t{"));
				sb.WriteLine(TEXT("\t\tint32 Count = Reader.ReadInt();"));
				sb.WriteLine(TEXT("\t\tfor(int32 i = 0; i < Count; i++)\n\t{"));
				sb.WriteLine(TEXT("\t\t\tthis->result.Add(*(reinterpret_cast<") + Type + TEXT("*>(Reader.TGReadObject())));"));
				sb.WriteLine(TEXT("\t\t}"));
				sb.WriteLine(TEXT("\t}"));
			}
		}
	}
	else if (Result == TEXT("bool"))
	{
		sb.WriteLine(TEXT("\t\tthis->result = Reader.ReadBool();"));
	}
	else
	{
		sb.WriteLine(TEXT("\tthis->result = MakeShareable(reinterpret_cast<") + Result + TEXT("*>(Reader.TGReadObject()));"));
		//sb.WriteLine("}");
	}
}
