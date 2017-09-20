#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoneCall.h"
#include "../../../Types/Private/PhoneCallDiscardReason.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace PHONE
{
class DiscardCall : public TLBaseObject
{
public:
	DiscardCall();
	DiscardCall(COMMON::InputPhoneCall* peer, int32 duration, PRIVATE::PhoneCallDiscardReason* reason, unsigned long long connection_id);

	~DiscardCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputPhoneCall* peer;
	 int32 duration;
	 PRIVATE::PhoneCallDiscardReason* reason;
	 unsigned long long connection_id;
	COMMON::Updates* result;
};
} //end namespace block
