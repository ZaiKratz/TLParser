#pragma once
#include "Engine.h"
#include "../../../Types/Private/PrivacyRule.h"

#include "../../../Types/Private/PrivacyRule.h"

//begin namespace block
namespace COMMON
{
class PrivacyValueAllowUsers : public PRIVATE::PrivacyRule
{
public:
	PrivacyValueAllowUsers();
	PrivacyValueAllowUsers(TArray<int32> users);

	~PrivacyValueAllowUsers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<int32> users;
};
} //end namespace block
