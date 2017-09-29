#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LangPackString.h"

//begin namespace block
namespace COMMON
{
class LangPackStringPluralized : public TLBaseObject
{
public:
	LangPackStringPluralized();
	LangPackStringPluralized(FString key, FString zero_value, FString one_value, FString two_value, FString few_value, FString many_value, FString other_value);

	~LangPackStringPluralized();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getkey() const
	{
		 return this->key;
	}

	FString GetZeroValue() const
	{
		 return this->zero_value;
	}

	FString GetOneValue() const
	{
		 return this->one_value;
	}

	FString GetTwoValue() const
	{
		 return this->two_value;
	}

	FString GetFewValue() const
	{
		 return this->few_value;
	}

	FString GetManyValue() const
	{
		 return this->many_value;
	}

	FString GetOtherValue() const
	{
		 return this->other_value;
	}

private:
	FString key;
	 FString zero_value;
	 FString one_value;
	 FString two_value;
	 FString few_value;
	 FString many_value;
	 FString other_value;
};
} //end namespace block
