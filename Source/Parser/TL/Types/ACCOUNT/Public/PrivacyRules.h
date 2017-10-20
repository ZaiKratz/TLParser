#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace ACCOUNT
{
class PrivacyRules : public TLBaseObject
{
public:
	PrivacyRules();
	PrivacyRules(TArray<TLBaseObject*> rules, TArray<COMMON::User*> users);

	~PrivacyRules();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<TLBaseObject*>  Getrules() const
	{
		 return this->rules;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

private:
	TArray<TLBaseObject*> rules;
	 TArray<COMMON::User*> users;
};
} //end namespace block
