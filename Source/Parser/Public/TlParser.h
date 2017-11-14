#pragma once
#include "Regex.h"
#include "TlObject.h"
#include "TLContainer.h"


class TLParser
{
public:
	static TArray<TLObject> GetTLObjectsFromTLFile(FString FilePath);
	static TArray<TLContainer> GetTLContainersFromFile(FString FilePath);
	static int32 FindLayer(FString FilePath);
};