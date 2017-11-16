#pragma once

#define _LOG(X, ...) UE_LOG(LogTemp, Warning, TEXT(X), __VA_ARGS__)

class TLContainer
{
public:

	TLContainer();

	TLContainer FromTL(const TArray<FString> &PossibleContainers);

	FString ToCamalCase(FString ClassName);

	//by name
	bool operator==(FString InName) const
	{
		return this->Name == InName;
	}
	bool operator!=(FString InName) const
	{
		return !operator==(InName);
	}

	bool IsConstructed() const
	{
		return Constructed;
	}

	bool IsCoreType()
	{
		return _IsCoreType;
	}


	FString Name;
	FString Namespace;
	TMap<FString, FString> ContainerArrays;
private:
	bool Constructed;
	bool _IsCoreType;
	TArray<FString> _CORE_TYPES = {
		"bc799737",// boolFalse#bc799737 = Bool;
		"997275b5", // boolTrue#997275b5 = Bool;
		"3fedd339", // true#3fedd339 = True;
		"1cb5c415", // vector#1cb5c415{ t:Type } # [t] = Vector t;
	};
};