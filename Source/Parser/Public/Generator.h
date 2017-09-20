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

	void CleanTLObjects();
	void GenerateTLObjects(FString SchemeFile, uint32 ImportDepth);
	FString GetFileName(TLObject tl);
	FString GetFile(FString Path);

private:
	void WriteHeaderCode(FString HeaderFilePath, TLObject& tl, TArray<FString> AbstractClasses, TArray<FString> CommonClasses, uint32 Depth);
	void WriteSourceCode(FString SourceFilePath, TLObject& tl, TArray<FString> AbstractClasses, TArray<FString> CommonClasses, uint32 Depth);
	void WriteAbstractClass(FString ClassName, FString FilePath);
	void WriteOnSendCode(TLSourceBuilder& sb, TLArg Arg, TArray<TLArg> Args, FString Name = TEXT(""));
	void WriteOnResponceCode(TLSourceBuilder& sb, TLObject tl, TLArg Arg, TArray<TLArg> Args, TArray<FString> AbstractClasses, TArray<FString> CommonClasses, FString Name = TEXT(""));
	void WriteRequestResultCode(TLSourceBuilder& sb, TLObject tl);

	FString _OutputDir;

};