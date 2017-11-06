#include "TlParser.h"
#include "FileHelper.h"


//This method yields TLObjects from a given .tl file
TArray<TLObject> TLParser::ParseFile(FString FilePath)
{
	TLObject Obj;
	TArray<TLObject> Objects;
	TArray<FString> Strings;

	bool IsFunction = false;

	FFileHelper::LoadANSITextFileToStrings(*(FilePath), NULL, Strings);

	for (auto String : Strings)
	{
		// Start by assuming that the next found line won't be a function (and will hence be a type)
		
		String = String.Trim();
		if (!String.StartsWith(TEXT("//")) && !String.IsEmpty())
		{
			FRegexPattern FuncPattern(TEXT("---(\\w+)---"));
			FRegexMatcher FuncMatch(FuncPattern, String);

			// Check whether the line is a type change (types ? functions) or not
			if (FuncMatch.FindNext())
			{
				IsFunction = FuncMatch.GetCaptureGroup(1) == TEXT("functions");
			}
			else
			{
				TLObject Object = Obj.FromTL(String, IsFunction);
				if(!Object.Name().IsEmpty())
					Objects.Add(Object);
			}
		}
	}
	return Objects;
}

// Finds the layer used on the specified scheme.tl file
int32 TLParser::FindLayer(FString FilePath)
{
	FRegexPattern LayerPattern(TEXT("^//\\s*LAYER\\s*(\\d+)$"));

	TArray<FString> Strings;
	FFileHelper::LoadANSITextFileToStrings(*(FilePath), NULL, Strings);

	for (auto String : Strings)
	{
		FRegexMatcher LayerMatch(LayerPattern, String);
		if (LayerMatch.FindNext())
			return FCString::Atoi(*LayerMatch.GetCaptureGroup(1));
	}
	return -1;
}
