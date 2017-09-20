#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPrivacyKey.h"
#include "../../../Types/Account/Public/PrivacyRules.h"

//begin namespace block
namespace ACCOUNT
{
class GetPrivacy : public TLBaseObject
{
public:
	GetPrivacy();
	GetPrivacy(PRIVATE::InputPrivacyKey* key);

	~GetPrivacy();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPrivacyKey* key;
	ACCOUNT::PrivacyRules* result;
};
} //end namespace block
