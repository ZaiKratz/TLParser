#pragma once

#define _LOG(X, ...) UE_LOG(LogTemp, Warning, TEXT(X), __VA_ARGS__)

class TLArg;
class TLContainer;

class TLObject
{
public:
	TLObject();
	TLObject(FString FullName, FString ObjectId, TArray<TLArg> Args, FString Result, const TArray<TLContainer> &TLContainers, bool IsFunction);
	TLObject FromTL(FString InStr, const TArray<TLContainer> &TLContainers, bool IsFunction);

	bool IsCoreType()
	{
		return _CORE_TYPES.Contains(this->_Id);
	}

	FString Name() const
	{
		return this->_Name;
	}
	void SetName(FString Name)
	{
		this->_Name = Name;
	}

	FString Namespace() const
	{
		return _Namespace;
	}

	FString Result() const
	{
		return _Result;
	}

	void SetResult(FString NewResult)
	{
		_Result = NewResult;
	}

	TArray<TLArg> &Args()
	{
		return _Args;
	}
	uint32 ID() const
	{
		return _Id;
	}
	bool IsFunction() const
	{
		return _IsFunction;
	}

	bool IsResultWasVector() const
	{
		return _ResultWasVector;
	}
	TArray<FString> SystemTypes
	{
		"FString", "int32", "long", "double", "bool", "uint8",
			"unsigned long long", "TBigInt<128>", "TBigInt<256>", "FDateTime",
			"delete", "public", "private", "static", "final"
	};
	

	uint32 InferID(FString FullName, FString ObjectID, TArray<TLArg> Args, const TArray<TLContainer> &TLContainers, FString Result);
	FString Repr(FString FullName, FString ObjectID, TArray<TLArg> Args, const TArray<TLContainer> &TLContainers, FString Result, bool IgnoreID = false);

private:
	TArray<uint32> _CORE_TYPES = {
		0xbc799737,// boolFalse#bc799737 = Bool;
		0x997275b5, // boolTrue#997275b5 = Bool;
		0x3fedd339, // true#3fedd339 = True;
		0x1cb5c415, // vector#1cb5c415{ t:Type } # [t] = Vector t;
	};
	FString _Namespace;
	FString _Name;
	FString _Result;
	TArray<TLArg> _Args;
	uint32 _Id;
	bool _IsFunction;
	bool _ResultWasVector = false;

	uint32 CRC32(const void * Data, int32 Size);
	
};

class TLArg
{
public:
	TLArg();
	TLArg(FString Name, const TArray<TLContainer> &TLContainers, FString ArgType);

	bool operator==(const TLArg &RHObject);
	bool operator!=(const TLArg &RHObject);

	FString Name() const
	{
		return _Name;
	}

	void SetName(FString NewName) 
	{
		_Name = NewName;
	}

	bool IsVector()const
	{
		return _IsVector;
	}
	void IsVector(bool Condition)
	{
		_IsVector = Condition;
	}

	bool IsFlag() const
	{
		return _IsFlag;
	}
	void IsFlag(bool Condition)
	{
		_IsFlag = Condition;
	}

	bool IsCanBeInferred() const
	{
		return _CanBeInferred;
	}
	bool IsGeneric() const
	{
		return _IsGeneric;
	}
	bool IsFlagIndicator() const
	{
		return _FlagIndicator;
	}
	bool IsUsingVectorID() const
	{
		return _UseVectorID;
	}

	FString Type() const
	{
		return _Type;
	}

	void SetType(FString NewType) 
	{
		_Type = NewType;
	}

	int32 FlagIndex() const
	{
		return _FlagIndex;
	}

	TArray<FString> SystemTypes
	{
		"FString", "int32", "long", "double", "bool", "uint8",
		"unsigned long long", "TBigInt<128>", "TBigInt<256>", "FDateTime",
		"delete", "public", "private", "static", "final"
	};

	bool IsBytes() const
	{
		return _IsBytes;
	}

	bool IsTrueType() const
	{
		return _TrueType;
	}

	bool IsContainer() const
	{
		return _IsContainer;
	}

	void IsContainer(bool Condition)
	{
		_IsContainer = Condition;
	}

	FString Repr(const TArray<TLContainer> &TLContainers);

private:
	FString _Name;
	bool _IsVector;
	bool _IsFlag;
	bool _IsGeneric;
	bool _CanBeInferred;
	bool _FlagIndicator;
	bool _UseVectorID;
	bool _IsBytes;
	bool _TrueType;
	bool _IsContainer;
	FString _Type;
	int32 _FlagIndex;

	
};