#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPrivacyKey.h"
#include "../../../Types/Private/InputPrivacyRule.h"
#include "../../../Types/Account/Public/PrivacyRules.h"

//begin namespace block
namespace ACCOUNT
{
class SetPrivacy : public TLBaseObject
{
public:
	SetPrivacy();
	SetPrivacy(PRIVATE::InputPrivacyKey* key, TArray<PRIVATE::InputPrivacyRule*> rules);

	~SetPrivacy();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::InputPrivacyKey*  Getkey() const
	{
		 return this->key;
	}

	TArray<PRIVATE::InputPrivacyRule*>  Getrules() const
	{
		 return this->rules;
	}

	ACCOUNT::PrivacyRules* GetResult() const
	{
		 return this->result;
	}

private:
	PRIVATE::InputPrivacyKey* key;
	 TArray<PRIVATE::InputPrivacyRule*> rules;
	ACCOUNT::PrivacyRules* result;
};
} //end namespace block
