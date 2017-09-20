#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputPrivacyRule.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Private/InputPrivacyRule.h"

//begin namespace block
namespace COMMON
{
class InputPrivacyValueAllowUsers : public PRIVATE::InputPrivacyRule
{
public:
	InputPrivacyValueAllowUsers();
	InputPrivacyValueAllowUsers(TArray<COMMON::InputUser*> users);

	~InputPrivacyValueAllowUsers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::InputUser*> users;
};
} //end namespace block
