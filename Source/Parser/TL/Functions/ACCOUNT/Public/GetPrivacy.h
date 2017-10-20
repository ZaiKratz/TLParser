#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Account/Public/PrivacyRules.h"

//begin namespace block
namespace ACCOUNT
{
class GetPrivacy : public TLBaseObject
{
public:
	GetPrivacy();
	GetPrivacy(TLBaseObject* key);

	~GetPrivacy();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getkey() const
	{
		 return this->key;
	}

	ACCOUNT::PrivacyRules* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* key;
	ACCOUNT::PrivacyRules* result;
};
} //end namespace block
