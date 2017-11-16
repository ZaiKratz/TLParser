#pragma once
#include "TlParser.h"
#include "SourceBuilder.h"

class TLGenerator
{
public:
	TLGenerator()
	{
		this->_OutputDir = TEXT("");
	}
	TLGenerator(FString OutputDir)
	{
		this->_OutputDir = OutputDir;
	}

	void Clean();
	void GenerateTLObjects(FString SchemeFile);
	void GenerateContainers(const TArray<TLContainer>& TLContainers);

private:
	void WriteHeaderCode(FString HeaderFilePath, TLObject& tl, const TArray<TLContainer> &TLContainers, const TArray<FString> &CommonClasses);
	void WriteSourceCode(FString SourceFilePath, TLObject& tl, const TArray<TLContainer> &TLContainers, const TArray<FString> &CommonClasses);
	void WriteOnSendCode(TLSourceBuilder& sb, TLArg Arg, TArray<TLArg> Args, FString Name = TEXT(""), bool Pointer = true);
	void WriteOnResponceCode(TLSourceBuilder& sb, TLObject tl, TLArg Arg, TArray<TLArg> Args, const TArray<TLContainer> &TLContainers, const TArray<FString> &CommonClasses, FString Name = TEXT(""));
	void WriteRequestResultCode(TLSourceBuilder& sb, TLObject tl);

	FString _OutputDir;
	FString Args;
	TArray<TLContainer> TLContainers;
	TArray<TLObject> TLObjects;
};