#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhoneCall.h"

//begin namespace block
namespace COMMON
{
class UpdatePhoneCall : public TLBaseObject
{
public:
	UpdatePhoneCall();
	UpdatePhoneCall(COMMON::PhoneCall* phone_call);

	~UpdatePhoneCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::PhoneCall*  GetPhoneCall() const
	{
		 return this->phone_call;
	}

private:
	COMMON::PhoneCall* phone_call;
};
} //end namespace block
