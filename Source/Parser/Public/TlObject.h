#pragma once

#define _LOG(X, ...) UE_LOG(LogTemp, Warning, TEXT(X), __VA_ARGS__)

class TLArg;

class TLObject
{
public:
	TLObject();
	TLObject(FString FullName, FString ObjectId, TArray<TLArg> Args, FString Result, bool IsFunction);
	TLObject FromTL(FString InStr, bool IsFunction);
	TArray<TLArg> SortedArgs();
	bool IsCoreType();

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

	TArray<FString> SystemTypes() const
	{
		return TArray<FString> 
		{ 
			"FString", "int32", "long", "double", "bool", "uint8",
				"unsigned long long", "TBigInt<128>", "TBigInt<256>", "FDateTime",
				"delete", "public", "private", "static"
		};
	}

	uint32 InferID(FString FullName, FString ObjectID, TArray<TLArg> Args, FString Result);
	FString Repr(FString FullName, FString ObjectID, TArray<TLArg> Args, FString Result, bool IgnoreID = false);

private:
	TArray<uint32> _CORE_TYPES;
	FString _Namespace;
	FString _Name;
	FString _Result;
	TArray<TLArg> _Args;
	uint32 _Id;
	bool _IsFunction;

	uint32 CRC32(const void * Data, int32 Size);
	
};

class TLArg
{
public:
	TLArg();
	TLArg(FString Name, FString ArgType);

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

	TArray<FString> SystemTypes() const
	{
		return TArray<FString>
		{
			"FString", "int32", "long", "double", "bool", "uint8",
				"unsigned long long", "TBigInt<128>", "TBigInt<256>", "FDateTime",
				"delete", "public", "private", "static"
		};
	}

	bool IsBytes() const
	{
		return _IsBytes;
	}

	FString Repr();

private:
	FString _Name;
	bool _IsVector;
	bool _IsFlag;
	bool _IsGeneric;
	bool _CanBeInferred;
	bool _FlagIndicator;
	bool _UseVectorID;
	bool _IsBytes;
	FString _Type;
	int32 _FlagIndex;

	
};