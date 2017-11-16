#include "TlObject.h"
#include "Regex.h"
#include <string>
#include <regex>
#include "TLContainer.h"

TLObject::TLObject()
{
	_ResultWasVector = false;
}

FString ToCamalCase(FString ClassName)
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

TLObject::TLObject(FString FullName, FString ObjectId, TArray<TLArg> Args, FString Result, const TArray<TLContainer> &TLContainers, bool IsFunction)
{
	if (FullName.Contains(TEXT(".")))
	{
		FullName.Split(TEXT("."), &this->_Namespace, &this->_Name);
		this->_Namespace = this->_Namespace.ToUpper();
		if (_Name.Contains(TEXT("_")))
			this->_Name = ToCamalCase(_Name);
		if (!_Name.IsEmpty())
			this->_Name[0] = toupper(this->_Name[0]);
	}
	else
	{
		this->_Namespace = TEXT("COMMON");
		if (FullName.Contains(TEXT("_")))
			this->_Name = ToCamalCase(FullName);
		else
			this->_Name = FullName;
		if(!_Name.IsEmpty())
			this->_Name[0] = toupper(this->_Name[0]);
	}

	this->_Args = Args;

// 	if (Result.Contains(TEXT("_")))
// 		this->_Result = ToCamalCase(Result);
// 	else
	this->_Result = Result;

	if (_Result.Contains(TEXT(".")))
		_Result.ReplaceInline(TEXT("."), TEXT("::"));
	

	if (!_Result.IsEmpty())
		if (_Result != TEXT("bool") && !this->SystemTypes.Contains(_Result))
			_Result[0] = toupper(_Result[0]);
		

	this->_IsFunction = IsFunction; 


	if (ObjectId.IsEmpty())
		this->_Id = InferID(FullName, ObjectId, Args, TLContainers, Result);
	else
	{
		ObjectId.InsertAt(0, "0x");
		std::string StdString(TCHAR_TO_UTF8(*ObjectId));
		uint32 x = strtoul(StdString.c_str(), NULL, 16);
		/*big endian*/
		this->_Id = x;
	}
}


TLObject TLObject::FromTL(FString InStr, const TArray<TLContainer> &TLContainers, bool IsFunction)
{
	FRegexPattern Pattern(
		TEXT("^([\\w.]+)(?:\\#([0-9a-f]+))?(?:\\s\\{?\\w+:[\\w\\d<>#.?!]+\\}?)*\\s=\\s([\\w\\d<>#.?]+);$")
	);
	FRegexMatcher Match(Pattern, InStr);

	FString FullName;
	FString ObjectId;
	FString Result;	

	if (Match.FindNext())
	{
		FullName = Match.GetCaptureGroup(1);
		ObjectId = Match.GetCaptureGroup(2);
		Result = Match.GetCaptureGroup(3);
	}


	FRegexPattern ArgsPattern(
		TEXT("(\\{)?(\\w+):([\\w\\d<>#.?!]+)(\\})?")
	);
	FRegexMatcher ArgsMatch(ArgsPattern, InStr);

	TArray<TLArg> Args;

	while (ArgsMatch.FindNext())
	{
		auto Braces = ArgsMatch.GetCaptureGroup(1);
		auto Name = ArgsMatch.GetCaptureGroup(2);
		auto Type = ArgsMatch.GetCaptureGroup(3);

		if (Braces.IsEmpty())
			if (Type == TEXT("X") || Type == TEXT("!X"))
			{
				Type = TEXT("TLBaseObject");
				Args.Add(TLArg(Name, TLContainers, Type));
			}
			else
				Args.Add(TLArg(Name, TLContainers, Type));
	}

	FRegexPattern VectorPattern(TEXT("[Vv]ector<(\\w+)>"));
	FRegexMatcher VectorMatch(VectorPattern, Result);

	if (VectorMatch.FindNext())
	{
		Result = VectorMatch.GetCaptureGroup(1);

		if (IsFunction)
		{
			if (Result.Contains(TEXT(".")))
			{
				FString TMPResult;
				FString TMPNamespace;
				Result.Split(TEXT("."), &TMPNamespace, &TMPResult);
				for (TLContainer Cont : TLContainers)
				{
					if (Cont.Namespace == TMPNamespace.ToUpper())
						if (Cont.Name.ToLower() == (TMPResult.ToLower()))
						{
							_ResultWasVector = true;
							Result = Cont.Namespace + TEXT("::") + Cont.Name + TEXT("_Container");
							break;
						}
				}
			}
			else
			{
				for (TLContainer Cont : TLContainers)
				{
					if (Cont.Name.ToLower() == (Result.ToLower()))
					{
						_ResultWasVector = true;
						Result = TEXT("COMMON::") + Cont.Name + TEXT("_Container");
						break;
					}

				}
			}
		}

		if (Result == TEXT("int"))
			Result = TEXT("TArray<int32>");

		else if (Result == TEXT("long"))
			Result = TEXT("TArray<unsigned long long>");

		else if (Result == TEXT("int128"))
			Result = TEXT("TArray<TBigInt<128>>");

		else if (Result == TEXT("int256"))
			Result = TEXT("TArray<TBigInt<256>>");

		else if (Result == TEXT("string"))
			Result = TEXT("TArray<FString>");

		else if (Result == TEXT("X"))
			Result = TEXT("TArray<TLBaseObject>");

		else if (Result.Contains(TEXT("Bool")))
			Result = TEXT("TArray<bool>");

		else if (this->SystemTypes.Contains(Result))
			Result = TEXT("TArray<") + Result + TEXT(">");

		else if(!IsResultWasVector())
			Result = TEXT("TArray<") + Result + TEXT(">");
	}
	else
	{
		if (IsFunction)
		{
			if (Result.Contains(TEXT(".")))
			{
				FString TMPResult;
				FString TMPNamespace;
				Result.Split(TEXT("."), &TMPNamespace, &TMPResult);
				for (TLContainer Cont : TLContainers)
				{
					if (Cont.Namespace == TMPNamespace.ToUpper())
						if (Cont.Name.ToLower() == (TMPResult.ToLower()))
						{
							_ResultWasVector = false;
							Result = Cont.Namespace + TEXT("::") + Cont.Name + TEXT("_Container");
							break;
						}
				}
			}
			else
			{
				for (TLContainer Cont : TLContainers)
				{
					if (Cont.Namespace == TEXT("COMMON"))
						if (Cont.Name.ToLower() == (Result.ToLower()))
						{
							_ResultWasVector = false;
							Result = TEXT("COMMON::") + Cont.Name + TEXT("_Container");
							break;
						}
							
				}
			}
		}

		if (Result == TEXT("int"))
			Result = TEXT("int32");

		else if (Result == TEXT("long"))
			Result = TEXT("unsigned long long");

		else if (Result == TEXT("int128"))
			Result = TEXT("TBigInt<128>");

		else if (Result == TEXT("int256"))
			Result = TEXT("TBigInt<256>");

		else if (Result == TEXT("string"))
			Result = TEXT("FString");

		else if (Result == TEXT("X"))
			Result = TEXT("TLBaseObject");

		else if (Result.Contains(TEXT("Bool")))
			Result = TEXT("bool");
	}
	return TLObject(FullName, ObjectId, Args, Result, TLContainers, IsFunction);
}

uint32 TLObject::CRC32(const void * Data, int32 Size)
{
	FCrc::Init();
	return FCrc::MemCrc32(Data, Size);
}

FString TLObject::Repr(FString FullName, FString ObjectID, TArray<TLArg> Args, const TArray<TLContainer> &TLContainers, FString Result, bool IgnoreID /*= false*/)
{
	FString HexID;
	if (ObjectID.IsEmpty() || IgnoreID)
		HexID = TEXT("");
	else
		HexID = TEXT("#") + ObjectID;

	FString RealArgs;
	if (this->Args().Num())
	{
		
		for (auto Arg : this->Args()) 
		{
			RealArgs += TEXT(" ");
			RealArgs += Arg.Repr(TLContainers);
		}
	}
	else
		RealArgs = TEXT("");

	return FullName + HexID + RealArgs + TEXT(" = ") + Result;
}

uint32 TLObject::InferID(FString FullName, FString ObjectID, TArray<TLArg> Args, const TArray<TLContainer> &TLContainers, FString Result)
{
	FString Representation = Repr(FullName, ObjectID, Args, TLContainers, Result);

	Representation =
		Representation.Replace(TEXT(":bytes"), TEXT(":string")).
		Replace(TEXT("?bytes"), TEXT("?string")).
		Replace(TEXT("<"), TEXT(" ")).
		Replace(TEXT(">"), TEXT("")).
		Replace(TEXT("{"), TEXT("")).
		Replace(TEXT("}"), TEXT(""));

	std::string StdString = TCHAR_TO_UTF8(*Representation);
	std::regex Pattern("\\w+:flags\\.\\d+?true"); 
	Representation = UTF8_TO_TCHAR(std::regex_replace(StdString, Pattern, "").c_str());

	return CRC32(TCHAR_TO_ANSI(*Representation), Representation.Len());
}

TLArg::TLArg()
{
	this->_IsBytes = false;
	this->_TrueType = false;
	this->_IsVector = false;
	this->_IsFlag = false;
	this->_IsContainer = false;
	this->_FlagIndex = -1;
}

TLArg::TLArg(FString Name, const TArray<TLContainer> &TLContainers, FString ArgType)
{
	this->_Name = Name;
	this->_IsBytes = false;
	this->_TrueType = false;
	this->_IsVector = false;
	this->_IsFlag = false;
	this->_IsContainer = false;
	this->_FlagIndex = -1;
	this->_UseVectorID = false;
	
	this->_CanBeInferred = Name == TEXT("random_id");

	// The type can be an indicator that other arguments will be flags
	if (ArgType == TEXT("#"))
	{
		this->_FlagIndicator = true;
		this->_Type = TEXT("");
		this->_IsGeneric = false;
	}
	else
	{
		this->_FlagIndicator = false;
		this->_IsGeneric = ArgType.StartsWith(TEXT("!"));
		ArgType.RemoveFromStart(TEXT("!")); // Strip the exclamation mark always to have only the name
		
		_Type = ArgType;

// 		if (_Type.Contains(TEXT(".")))
// 		{
// 			FString TMPResult;
// 			FString TMPNamespace;
// 			_Type.Split(TEXT("."), &TMPNamespace, &TMPResult);
// 			for (TLContainer Cont : TLContainers)
// 			{
// 				if (!Cont.Namespace.IsEmpty())
// 					if (Cont.Name.ToLower() == (TMPResult.ToLower()))
// 						_Type = Cont.Namespace + TEXT("_") + Cont.Name + TEXT("_Container");
// 			}
// 		}
// 		else
// 		{
// 			for (TLContainer Cont : TLContainers)
// 			{
// 				if (Cont.Namespace.IsEmpty())
// 					if (Cont.Name.ToLower() == (_Type.ToLower()))
// 						_Type = Cont.Name + TEXT("_Container");
// 			}
// 		}

		

		if (_Type == TEXT("int"))
			this->_Type = TEXT("int32");

		else if (_Type == TEXT("long"))
			this->_Type = TEXT("unsigned long long");

		else if (_Type == TEXT("int128"))
			this->_Type = TEXT("TBigInt<128>");

		else if (_Type == TEXT("int256"))
			this->_Type = TEXT("TBigInt<256>");

		else if (_Type == TEXT("bytes"))
		{
			this->_IsBytes = true;
			this->_Type = TEXT("uint8");
		}

		else if(_Type == TEXT("string"))
			this->_Type = TEXT("FString");

// 		else
// 		{
// 			if (_Type.Contains(TEXT(".")))
// 			{
// 				FString TMPName;
// 				FString TMPNamespace;
// 				_Type.Split(TEXT("."), &TMPNamespace, &TMPName);
// 				if (TLContainers.Contains(TMPName))
// 				{
// 					auto TLCont = TLContainers.FindByKey(TMPName);
// 					if (TLCont->Namespace.IsEmpty())
// 						_Type = TLCont->Name + TEXT("_Container");
// 					else
// 						_Type = TLCont->Namespace + TEXT("_") + TLCont->Name + TEXT("_Container");
// 				}
// 			}
// 			else
// 			{
// 				if (TLContainers.Contains(_Type))
// 				{
// 					auto TLCont = TLContainers.FindByKey(_Type);
// 					if (TLCont->Namespace.IsEmpty())
// 						_Type = TLCont->Name + TEXT("_Container");
// 					else
// 						_Type = TLCont->Namespace + TEXT("_") + TLCont->Name + TEXT("_Container");
// 				}
// 			}
// 		}
	}

// 	# The type may be a flag (flags.IDX?REAL_TYPE)
// 	# Note that 'flags' is NOT the flags name; this is determined by a previous argument
// 	# However, we assume that the argument will always be called 'flags'
	

	FRegexPattern FlagPattern(TEXT("flags.(\\d+)\\?([\\w<>.]+)"));
	FRegexMatcher FlagMatch(FlagPattern, this->_Type);

	if (FlagMatch.FindNext())
	{
		this->_IsFlag = true;
		this->_FlagIndex = FCString::Atoi(*FlagMatch.GetCaptureGroup(1));

		// Update the type to match the exact type, not the "flagged" one
		this->_Type = FlagMatch.GetCaptureGroup(2);

		

// 		if (_Type.Contains(TEXT(".")))
// 		{
// 			FString TMPResult;
// 			FString TMPNamespace;
// 			_Type.Split(TEXT("."), &TMPNamespace, &TMPResult);
// 			for (TLContainer Cont : TLContainers)
// 			{
// 				if (!Cont.Namespace.IsEmpty())
// 					if (Cont.Name.ToLower() == (TMPResult.ToLower()))
// 						_Type = Cont.Namespace + TEXT("_") + Cont.Name + TEXT("_Container");
// 			}
// 		}
// 		else
// 		{
// 			for (TLContainer Cont : TLContainers)
// 			{
// 				if (Cont.Namespace.IsEmpty())
// 					if (Cont.Name.ToLower() == (_Type.ToLower()))
// 						_Type = Cont.Name + TEXT("_Container");
// 			}
// 		}

		if (_Type == TEXT("int"))
			this->_Type = TEXT("int32");

		else if (_Type == TEXT("Bool"))
			_Type[0] = tolower(_Type[0]);

		else if (_Type == TEXT("true"))
			_TrueType = true;

		else if (_Type == TEXT("long"))
			this->_Type = TEXT("unsigned long long");

		else if (_Type == TEXT("int128"))
			this->_Type = TEXT("TBigInt<128>");

		else if (_Type == TEXT("int256"))
			this->_Type = TEXT("TBigInt<256>");

		else if (_Type == TEXT("bytes"))
		{
			this->_IsBytes = true;
			this->_Type = TEXT("uint8");
		}

		else if (_Type == TEXT("string"))
			this->_Type = TEXT("FString");

		
	}

	// Then check if the type is a Vector<REAL_TYPE>
	FRegexPattern VectorPattern(TEXT("[Vv]ector<(\\w+)>"));
	FRegexMatcher VectorMatch(VectorPattern, this->_Type);

	if (VectorMatch.FindNext())
	{
		this->_IsVector = true;
		this->_UseVectorID = this->_Type[0] == TEXT('V');
		this->_Type = VectorMatch.GetCaptureGroup(1);

// 		if (_Type.Contains(TEXT(".")))
// 		{
// 			FString TMPResult;
// 			FString TMPNamespace;
// 			_Type.Split(TEXT("."), &TMPNamespace, &TMPResult);
// 			for (TLContainer Cont : TLContainers)
// 			{
// 				if (!Cont.Namespace.IsEmpty())
// 					if (Cont.Name.ToLower() == (TMPResult.ToLower()))
// 						_Type = Cont.Namespace + TEXT("_") + Cont.Name + TEXT("_Container");
// 			}
// 		}
// 		else
// 		{
// 			for (TLContainer Cont : TLContainers)
// 			{
// 				if (Cont.Namespace.IsEmpty())
// 					if (Cont.Name.ToLower() == (_Type.ToLower()))
// 						_Type = Cont.Name + TEXT("_Container");
// 			}
// 		}

		if (_Type == TEXT("int"))
			this->_Type = TEXT("int32");

		else if (_Type == TEXT("Bool"))
			_Type[0] = tolower(_Type[0]);

		else if (_Type == TEXT("string"))
			this->_Type = this->_Type.Replace(TEXT("string"), TEXT("FString"));

		else if (_Type == TEXT("long"))
			this->_Type = TEXT("unsigned long long");

		else if (_Type == TEXT("int128"))
			this->_Type = TEXT("TBigInt<128>");

		else if (_Type == TEXT("int256"))
			this->_Type = TEXT("TBigInt<256>");

// 		else
// 		{
// 			if (_Type.Contains(TEXT(".")))
// 			{
// 				FString TMPName;
// 				FString TMPNamespace;
// 				_Type.Split(TEXT("."), &TMPNamespace, &TMPName);
// 				if (TLContainers.Contains(TMPName))
// 				{
// 					auto TLCont = TLContainers.FindByKey(TMPName);
// 					if (TLCont->Namespace.IsEmpty())
// 						_Type = TLCont->Name + TEXT("_Container");
// 					else
// 						_Type = TLCont->Namespace + TEXT("_") + TLCont->Name + TEXT("_Container");
// 				}
// 			}
// 			else
// 			{
// 				if (TLContainers.Contains(_Type))
// 				{
// 					auto TLCont = TLContainers.FindByKey(_Type);
// 					if (TLCont->Namespace.IsEmpty())
// 						_Type = TLCont->Name + TEXT("_Container");
// 					else
// 						_Type = TLCont->Namespace + TEXT("_") + TLCont->Name + TEXT("_Container");
// 				}
// 			}
// 		}
	}

	// Then check if the type is a Container	
	if (_Type.Contains(TEXT(".")))
	{
		FString TMPName;
		FString TMPNamespace;
		_Type.Split(TEXT("."), &TMPNamespace, &TMPName);
		for (TLContainer Cont : TLContainers)
		{
			if (Cont.Namespace == TMPNamespace.ToUpper())
				if (Cont.Name.ToLower() == (TMPName.ToLower()))
				{
					_Type = Cont.Namespace + TEXT("::") + Cont.Name + TEXT("_Container");
					_IsContainer = true;
					_IsVector = false; //Disable if arg was vector
					break;
				}
		}
		
	}
	else
	{
		for (TLContainer Cont : TLContainers)
		{
			if (Cont.Namespace == TEXT("COMMON"))
				if (Cont.Name.ToLower() == (_Type.ToLower()))
				{
					_Type = TEXT("COMMON::") + Cont.Name + TEXT("_Container");
					_IsContainer = true;
					_IsVector = false; //Disable if arg was vector
					break;
				}
		}
		
	}
	

// 	# The name may contain "date" in it, if this is the case and the type is "int",
// 	# we can safely assume that this should be treated as a "date" object.
// 	# Note that this is not a valid Telegram object, but it's easier to work with
	FRegexPattern DatePattern(TEXT("(\\b|_)date\\b"));
	FRegexMatcher DateMatch(DatePattern, this->_Name);
	TArray<FString> AnonymousList = { TEXT("expires"), TEXT("expires_at"), TEXT("was_online") };

	if (this->_Type == TEXT("int32") && (DateMatch.FindNext() || AnonymousList.Contains(this->_Name)))
	{
		this->_Type = TEXT("FDateTime");
	}

// 	if (_Type.Contains(TEXT("_")))
// 		_Type = ToCamalCase(_Type);
	if (_Type.Contains(TEXT(".")))
		_Type.ReplaceInline(TEXT("."), TEXT("::"));
}

FString TLArg::Repr(const TArray<TLContainer> &TLContainers)
{
	auto RealType = this->Type();

	if(RealType.Contains(TEXT("Container")))
	{
		FRegexPattern PatternWithNamespace(TEXT("(\\w+)::(\\w+)(_\\w+)"));
		FRegexMatcher MatchWithNamespace(PatternWithNamespace, RealType);

		if (MatchWithNamespace.FindNext())
		{
			FString qwe = MatchWithNamespace.GetCaptureGroup(1);
			qwe.RemoveFromEnd(TEXT("_"));
			RealType = qwe.ToLower() + TEXT(".") + MatchWithNamespace.GetCaptureGroup(2);
		}
		else
		{
			FRegexPattern PatternWithoutNamespace(TEXT("(\\w+)(_\\w+)"));
			FRegexMatcher MatchWithoutNamespace(PatternWithoutNamespace, RealType);

			if (MatchWithoutNamespace.FindNext())
				RealType = MatchWithoutNamespace.GetCaptureGroup(1);
		}
	}

	else if (RealType == TEXT("int32"))
		RealType = TEXT("int");
	else if (RealType == TEXT("bool"))
		RealType = TEXT("Bool");

	else if (RealType == TEXT("FString"))
		RealType.ReplaceInline(TEXT("FString"), TEXT("string"));

	else if (RealType == TEXT("unsigned long long"))
		RealType = TEXT("long");

	else if (RealType == TEXT("TBigInt<128>"))
		RealType = TEXT("int128");

	else if (RealType == TEXT("TBigInt<256>"))
		RealType = TEXT("int256");

	else if (RealType == TEXT("FDateTime"))
		RealType = TEXT("int");

	if (this->IsFlagIndicator())
	{
		RealType = TEXT("#");
	}

	if (this->IsVector())
	{
		if (RealType.Contains(TEXT("Container")))
		{
			FRegexPattern Pattern(TEXT("(\\w+_)(\\w+)(_\\w+)"));
			FRegexMatcher Match(Pattern, RealType);

			if (Match.FindNext())
			{
				FString qwe = Match.GetCaptureGroup(1);
				qwe.RemoveFromEnd(TEXT("_"));
				RealType = qwe.ToLower() + TEXT(".") + Match.GetCaptureGroup(2);
			}
		}

		if (this->IsUsingVectorID())
			RealType = TEXT("Vector<") + RealType + TEXT(">");
		else
			RealType = TEXT("vector<") + RealType + TEXT(">");
	}

	if (this->IsGeneric())
		RealType = TEXT("!") + RealType;

	if (this->IsFlag())
	{
		if (RealType.Contains(TEXT("Container")))
		{
			FRegexPattern PatternWithNamespace(TEXT("(\\w+_)(\\w+)(_\\w+)"));
			FRegexMatcher MatchWithNamespace(PatternWithNamespace, RealType);

			if (MatchWithNamespace.FindNext())
			{
				FString qwe = MatchWithNamespace.GetCaptureGroup(1);
				qwe.RemoveFromEnd(TEXT("_"));
				RealType = qwe.ToLower() + TEXT(".") + MatchWithNamespace.GetCaptureGroup(2);
			}
			else
			{
				FRegexPattern PatternWithoutNamespace(TEXT("(\\w+)(_\\w+)"));
				FRegexMatcher MatchWithoutNamespace(PatternWithoutNamespace, RealType);

				if (MatchWithoutNamespace.FindNext())
					RealType = MatchWithoutNamespace.GetCaptureGroup(1);
			}
		}
		RealType = TEXT("flags.") + FString::FromInt(this->FlagIndex()) + TEXT("?") + RealType;
	}
		

	return this->Name() + TEXT(":") + RealType;
}

bool TLArg::operator==(const TLArg &RHObject)
{
	return
		_CanBeInferred == RHObject._CanBeInferred &&
		_FlagIndex == RHObject._FlagIndex &&
		_FlagIndicator == RHObject._FlagIndicator &&
		_IsFlag == RHObject._IsFlag &&
		_IsGeneric == RHObject._IsGeneric &&
		_IsVector == RHObject._IsVector &&
		_Name == RHObject._Name &&
		_Type == RHObject._Type &&
		_UseVectorID == RHObject._UseVectorID &&
		_IsBytes == RHObject._IsBytes &&
		_TrueType == RHObject._TrueType &&
		_IsContainer == RHObject._IsContainer;
}

bool TLArg::operator!=(const TLArg &RHObject)
{
	return !operator==(RHObject);
}

