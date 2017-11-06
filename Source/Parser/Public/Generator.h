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
	void GenerateTLObjects(FString SchemeFile);

	void WriteAllObjects(TArray<TLObject> TLObjects, FString FuncDir, FString TypesDir, IPlatformFile &PlatformFile, TArray<FString> AbstractTypes, TArray<FString> CommonNames, FString SchemeFile, FString PluginContentDir);

	FString GetFileName(TLObject tl);
	FString GetFile(FString Path);

private:
	void WriteHeaderCode(FString HeaderFilePath, TLObject& tl, TArray<FString> AbstractClasses, TArray<FString> CommonClasses);
	void WriteSourceCode(FString SourceFilePath, TLObject& tl, TArray<FString> AbstractClasses, TArray<FString> CommonClasses);
	void WriteOnSendCode(TLSourceBuilder& sb, TLArg Arg, TArray<TLArg> Args, FString Name = TEXT(""), bool Pointer = true);
	void WriteOnResponceCode(TLSourceBuilder& sb, TLObject tl, TLArg Arg, TArray<TLArg> Args, TArray<FString> AbstractClasses, TArray<FString> CommonClasses, FString Name = TEXT(""));
	void WriteRequestResultCode(TLSourceBuilder& sb, TLObject tl);

	FString _OutputDir;
	FString Args;

};