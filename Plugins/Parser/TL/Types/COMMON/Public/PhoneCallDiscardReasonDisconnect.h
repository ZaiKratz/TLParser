#pragma once
#include "Engine.h"
#include "../../../Types/Private/PhoneCallDiscardReason.h"

#include "../../../Types/Private/PhoneCallDiscardReason.h"

//begin namespace block
namespace COMMON
{
class PhoneCallDiscardReasonDisconnect : public PRIVATE::PhoneCallDiscardReason
{
public:
	PhoneCallDiscardReasonDisconnect();
	~PhoneCallDiscardReasonDisconnect();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
