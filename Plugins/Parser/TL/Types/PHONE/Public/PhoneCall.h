#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhoneCall.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace PHONE
{
class PhoneCall : public TLBaseObject
{
public:
	PhoneCall();
	PhoneCall(COMMON::PhoneCall* phone_call, TArray<COMMON::User*> users);

	~PhoneCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::PhoneCall* phone_call;
	 TArray<COMMON::User*> users;
};
} //end namespace block