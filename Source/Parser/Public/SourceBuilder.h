#pragma once
#include "Engine.h"

class TLSourceBuilder
{
public:
	void WriteLine(FString Line);
	void Write(FString Words);
	FString ReturnGeneratedCode();
private:
	FString Code;
};