#include "SourceBuilder.h"


void TLSourceBuilder::WriteLine(FString Line)
{
	Code += Line + TEXT("\n");
}

void TLSourceBuilder::Write(FString Words)
{
	Code += Words;
}

FString TLSourceBuilder::ReturnGeneratedCode()
{
	return Code;
}

