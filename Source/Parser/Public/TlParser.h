#pragma once
#include "Regex.h"
#include "TlObject.h"
#include "TLContainer.h"


class TLParser
{
public:
	static TArray<TLObject> ParseTLObjectsFromTLFile(FString FilePath);
	static TArray<TLContainer> ParseTLContainersFromFile(FString FilePath);
	static int32 FindLayer(FString FilePath);
};