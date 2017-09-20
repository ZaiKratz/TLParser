#pragma once
#include "Regex.h"
#include "TlObject.h"


class TLParser
{
public:
	static TArray<TLObject> ParseFile(FString FilePath);
	static int32 FindLayer(FString FilePath);
};