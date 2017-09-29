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

	COMMON::InputPhoneCall*  Getpeer() const
	{
		 return this->peer;
	}

	int32 Getduration() const
	{
		 return this->duration;
	}

	PRIVATE::PhoneCallDiscardReason*  Getreason() const
	{
		 return this->reason;
	}

	unsigned long long GetConnectionId() const
	{
		 return this->connection_id;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputPhoneCall* peer;
	 int32 duration;
	 PRIVATE::PhoneCallDiscardReason* reason;
	 unsigned long long connection_id;
	COMMON::Updates* result;
};
} //end namespace block
