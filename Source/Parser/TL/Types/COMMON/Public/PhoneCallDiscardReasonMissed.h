#pragma once
#include "Engine.h"
#include "../../../Types/Private/PhoneCallDiscardReason.h"

#include "../../../Types/Private/PhoneCallDiscardReason.h"

//begin namespace block
namespace COMMON
{
class PhoneCallDiscardReasonMissed : public PRIVATE::PhoneCallDiscardReason
{
public:
	PhoneCallDiscardReasonMissed();
	~PhoneCallDiscardReasonMissed();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
