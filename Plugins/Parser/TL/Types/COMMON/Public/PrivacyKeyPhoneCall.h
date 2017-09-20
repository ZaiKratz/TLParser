#pragma once
#include "Engine.h"
#include "../../../Types/Private/PrivacyKey.h"

#include "../../../Types/Private/PrivacyKey.h"

//begin namespace block
namespace COMMON
{
class PrivacyKeyPhoneCall : public PRIVATE::PrivacyKey
{
public:
	PrivacyKeyPhoneCall();
	~PrivacyKeyPhoneCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
