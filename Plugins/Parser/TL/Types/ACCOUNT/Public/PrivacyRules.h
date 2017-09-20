#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/PrivacyRule.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace ACCOUNT
{
class PrivacyRules : public TLBaseObject
{
public:
	PrivacyRules();
	PrivacyRules(TArray<PRIVATE::PrivacyRule*> rules, TArray<COMMON::User*> users);

	~PrivacyRules();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<PRIVATE::PrivacyRule*> rules;
	 TArray<COMMON::User*> users;
};
} //end namespace block
