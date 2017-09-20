#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputPrivacyRule.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Private/InputPrivacyRule.h"

//begin namespace block
namespace COMMON
{
class InputPrivacyValueDisallowUsers : public PRIVATE::InputPrivacyRule
{
public:
	InputPrivacyValueDisallowUsers();
	InputPrivacyValueDisallowUsers(TArray<COMMON::InputUser*> users);

	~InputPrivacyValueDisallowUsers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::InputUser*> users;
};
} //end namespace block
