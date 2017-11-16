#include "TLContainer.h"
#include "Regex.h"

TLContainer::TLContainer()
{
	Name = "";
	Namespace = "";
	Constructed = false;
	_IsCoreType = false;
}

TLContainer TLContainer::FromTL(const TArray<FString> &PossibleContainers)
{
	Constructed = false;
	_IsCoreType = false;
	TMap<FString, FString> Names;
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
			FString ID = Match.GetCaptureGroup(2);
			if (_CORE_TYPES.Contains(ID))
			{
				_IsCoreType = true;
				Constructed = false;
				return Container;
			}
			if (!TMPName.IsEmpty()) 
			{
				if (TMPName.Contains(TEXT(".")))
				{
					TMPName.Split(TEXT("."), &Container.Namespace, &TMPName);
					Container.Namespace.ToUpperInline();
				}
				TMPName[0] = toupper(TMPName[0]);

				Names.Add(ID, TMPName + TEXT("Array"));
			}
	
			FString TMPResult = Match.GetCaptureGroup(3);
			if (!TMPResult.IsEmpty())
			{
				TMPResult[0] = toupper(TMPResult[0]);

				if (TMPResult.Contains(TEXT(".")))
				{
					FString TMPNamespace;
					TMPResult.Split(TEXT("."), &TMPNamespace, &TMPResult);
					Results.AddUnique(TMPResult);
				}
				else
					Results.AddUnique(TMPResult);
			}
		}
	}

	if (Results.Num() != 1)
		return Container;
	else
	{
		for (auto Name : Names)
		{
			if (Results[0].ToLower() == Name.Value)
			{
				Container.Name = Name.Value;
				if (Container.Namespace.IsEmpty())
					Container.Namespace = TEXT("COMMON");
			}
				
		}
		if (Container.Name.IsEmpty())
		{
			Container.Name = Results[0];
			if (Container.Namespace.IsEmpty())
				Container.Namespace = TEXT("COMMON");
		}

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
