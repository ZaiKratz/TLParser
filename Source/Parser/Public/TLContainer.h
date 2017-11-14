#pragma once

#define _LOG(X, ...) UE_LOG(LogTemp, Warning, TEXT(X), __VA_ARGS__)

class TLContainer
{
public:
	TLContainer();

	TLContainer FromTL(const TArray<FString> &PossibleContainers);

	FString ToCamalCase(FString ClassName);
	FString Name;
	FString Namespace;
	TArray<FString> ContainerArrays;
	bool Constructed;
};