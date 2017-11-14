#include "TlParser.h"
#include "FileHelper.h"


//This method yields TLObjects from a given .tl file
TArray<TLObject> TLParser::GetTLObjectsFromTLFile(FString FilePath)
{
	TLObject Obj;
	TArray<TLObject> Objects;
	TArray<FString> Strings;

	bool IsFunction = false;

	FFileHelper::LoadANSITextFileToStrings(*(FilePath), NULL, Strings);

	for (int32 Index = 0; Index < Strings.Num(); Index++)
	{
		// Start by assuming that the next found line won't be a function (and will hence be a type)
		
		Strings[Index] = Strings[Index].Trim();
		if (!Strings[Index].StartsWith(TEXT("//")) && !Strings[Index].IsEmpty())
		{
			if (Strings[Index].StartsWith(TEXT("---")))
			{
				FRegexPattern FuncPattern(TEXT("---(\\w+)---"));
				FRegexMatcher FuncMatch(FuncPattern, Strings[Index]);

				// Check whether the line is a type change (types ? functions) or not
				if (FuncMatch.FindNext())
				{
					IsFunction = FuncMatch.GetCaptureGroup(1) == TEXT("functions");
				}
			}
			else
			{
				TLObject Object = Obj.FromTL(Strings[Index], IsFunction);
				if (!Object.Name().IsEmpty())
					Objects.Add(Object);
			}
		}
	}

	return Objects;
}



TArray<TLContainer> TLParser::GetTLContainersFromFile(FString FilePath)
{
	TMap<uint32, TArray<FString>> PossibleContainers;
	TArray<FString> Strings;

	bool IsFunction = false;

	FFileHelper::LoadANSITextFileToStrings(*(FilePath), NULL, Strings);

	for (int32 Index = 0; Index < Strings.Num(); Index++)
	{
		if (Strings[Index].StartsWith(TEXT("---")))
		{
			FRegexPattern FuncPattern(TEXT("---(\\w+)---"));
			FRegexMatcher FuncMatch(FuncPattern, Strings[Index]);

			// Check whether the line is a type change (types ? functions) or not
			if (FuncMatch.FindNext())
			{
				IsFunction = FuncMatch.GetCaptureGroup(1) == TEXT("functions");
			}
		}

		if (!IsFunction)
		{
			if ((Index + 1) <= Strings.Num())
			{
				if (Strings[Index + 1] != TEXT("") || Strings[Index + 1] != TEXT("//") || !Strings[Index + 1].StartsWith(TEXT("---")))
				{
					int32 Key = Index + 1;
					TArray<FString> Classes;
					for (int32 I = Index; I < Strings.Num(); I++)
					{
						Classes.Add(Strings[I]);
						if ((I + 1) <= Strings.Num())
							if (Strings[I + 1] == TEXT("") || Strings[I + 1] == TEXT("//") || Strings[I + 1].StartsWith(TEXT("---")))
							{
								Index = I + 1;
								break;
							}
					}
					if (Classes.Num() > 1)
						PossibleContainers.Add(Key, Classes);
				}
			}
		}
	}

	TArray<TLContainer> Containers;
	TLContainer TLCont;
	for (auto Cont : PossibleContainers)
	{
		TLContainer Container = TLCont.FromTL(Cont.Value);
		if(Container.Constructed)
			Containers.Add(Container);
	}
		

	return Containers;
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
