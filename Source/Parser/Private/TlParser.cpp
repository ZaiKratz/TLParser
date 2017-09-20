#include "TlParser.h"
#include "FileHelper.h"


//This method yields TLObjects from a given .tl file
TArray<TLObject> TLParser::ParseFile(FString FilePath)
{
	TLObject obj;
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
				auto tlobj = obj.FromTL(String, IsFunction);
				if(!tlobj.Name().IsEmpty())
					Objects.Add(tlobj);
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
