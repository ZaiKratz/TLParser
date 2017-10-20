#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageActionPhoneCall : public TLBaseObject
{
public:
	MessageActionPhoneCall();
	MessageActionPhoneCall(unsigned long long call_id, TLBaseObject* reason, int32 duration);

	~MessageActionPhoneCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetCallId() const
	{
		 return this->call_id;
	}

	TLBaseObject*  Getreason() const
	{
		 return this->reason;
	}

	int32 Getduration() const
	{
		 return this->duration;
	}

private:
	unsigned long long call_id;
	 TLBaseObject* reason;
	 int32 duration;
};
} //end namespace block
