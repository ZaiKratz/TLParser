#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputPrivacyKey.h"

#include "../../../Types/Private/InputPrivacyKey.h"

//begin namespace block
namespace COMMON
{
class InputPrivacyKeyStatusTimestamp : public PRIVATE::InputPrivacyKey
{
public:
	InputPrivacyKeyStatusTimestamp();
	~InputPrivacyKeyStatusTimestamp();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
