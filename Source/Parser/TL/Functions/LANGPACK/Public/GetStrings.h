#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LangPackString.h"

//begin namespace block
namespace LANGPACK
{
class GetStrings : public TLBaseObject
{
public:
	GetStrings();
	GetStrings(FString lang_code, TArray<FString> keys);

	~GetStrings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString GetLangCode() const
	{
		 return this->lang_code;
	}

	TArray<FString>  Getkeys() const
	{
		 return this->keys;
	}

	TArray<COMMON::LangPackString*> GetResult() const
	{
		 return this->result;
	}

private:
	FString lang_code;
	 TArray<FString> keys;
	TArray<COMMON::LangPackString*> result;
};
} //end namespace block
