#pragma once
#include "Engine.h"
#include "../../../Types/Private/PrivacyKey.h"

#include "../../../Types/Private/PrivacyKey.h"

//begin namespace block
namespace COMMON
{
class PrivacyKeyChatInvite : public PRIVATE::PrivacyKey
{
public:
	PrivacyKeyChatInvite();
	~PrivacyKeyChatInvite();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
