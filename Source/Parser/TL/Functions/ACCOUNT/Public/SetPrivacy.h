#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Account/Public/PrivacyRules.h"

//begin namespace block
namespace ACCOUNT
{
class SetPrivacy : public TLBaseObject
{
public:
	SetPrivacy();
	SetPrivacy(TLBaseObject* key, TArray<TLBaseObject*> rules);

	~SetPrivacy();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getkey() const
	{
		 return this->key;
	}

	TArray<TLBaseObject*>  Getrules() const
	{
		 return this->rules;
	}

	ACCOUNT::PrivacyRules* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* key;
	 TArray<TLBaseObject*> rules;
	ACCOUNT::PrivacyRules* result;
};
} //end namespace block
