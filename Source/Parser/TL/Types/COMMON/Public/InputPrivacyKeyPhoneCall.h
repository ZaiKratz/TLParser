#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputPrivacyKey.h"

#include "../../../Types/Private/InputPrivacyKey.h"

//begin namespace block
namespace COMMON
{
class InputPrivacyKeyPhoneCall : public PRIVATE::InputPrivacyKey
{
public:
	InputPrivacyKeyPhoneCall();
	~InputPrivacyKeyPhoneCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
