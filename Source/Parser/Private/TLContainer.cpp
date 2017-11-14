#include "TLContainer.h"
#include "Regex.h"

TLContainer::TLContainer()
{
	Name = "";
	Namespace = "";
	Constructed = false;
}

TLContainer TLContainer::FromTL(const TArray<FString> &PossibleContainers)
{
	TArray<FString> Names;
	TArray<FString> Results;

	TLContainer Container;

	for (FString Str : PossibleContainers)
	{
		FRegexPattern Pattern(
			TEXT("^([\\w.]+)(?:\\#([0-9a-f]+))?(?:\\s\\{?\\w+:[\\w\\d<>#.?!]+\\}?)*\\s=\\s([\\w\\d<>#.?]+);$")
		);
		FRegexMatcher Match(Pattern, Str);
		if (Match.FindNext())
		{
			FString TMPName = Match.GetCaptureGroup(1);
			if (!TMPName.IsEmpty()) 
			{
				if (TMPName.Contains(TEXT(".")))
				{
					TMPName.Split(TEXT("."), &Container.Namespace, &TMPName);
					Container.Namespace.ToUpperInline();
				}
				TMPName[0] = toupper(TMPName[0]);
				if (TMPName.Contains(TEXT("_")))
					TMPName = ToCamalCase(TMPName);
				Names.Add(TMPName);
			}
	
			FString TMPResult = Match.GetCaptureGroup(3);
			if (!TMPResult.IsEmpty())
			{
				TMPResult[0] = toupper(TMPResult[0]);
				if (TMPResult.Contains(TEXT("_")))
					TMPResult = ToCamalCase(TMPResult);
				if (TMPResult.Contains(TEXT(".")))
					TMPResult.ReplaceInline(TEXT("."), TEXT("_"));
				Results.AddUnique(TMPResult);
			}
		}
	}

	if (Results.Num() > 1 || Results.Num() < 1)
		return Container;
	else
	{
		for (FString Name : Names)
		{
			if (Results[0].ToLower() == Name.ToLower())
				Container.Name = Name;
		}
		if (Container.Name.IsEmpty())
			Container.Name = Results[0];

		Container.ContainerArrays = Names;
		Container.Constructed = true;
		return Container;
	}
}

FString TLContainer::ToCamalCase(FString ClassName)
{
	FRegexPattern Pattern(
		TEXT("((?i)[a-z]+\\d?)_*")
	);
	FRegexMatcher Match(Pattern, ClassName);

	FString CamalClassName;
	while (Match.FindNext())
	{
		FString tmp = Match.GetCaptureGroup(1);
		tmp[0] = toupper(tmp[0]);
		CamalClassName += tmp;
	}
	return CamalClassName;
}