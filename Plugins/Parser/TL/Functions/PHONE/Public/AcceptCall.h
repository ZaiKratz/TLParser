#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoneCall.h"
#include "../../../Types/Common/Public/PhoneCallProtocol.h"
#include "../../../Types/Phone/Public/PhoneCall.h"

//begin namespace block
namespace PHONE
{
class AcceptCall : public TLBaseObject
{
public:
	AcceptCall();
	AcceptCall(COMMON::InputPhoneCall* peer, TArray<uint8> g_b, COMMON::PhoneCallProtocol* protocol);

	~AcceptCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputPhoneCall* peer;
	 TArray<uint8> g_b;
	 COMMON::PhoneCallProtocol* protocol;
	PHONE::PhoneCall* result;
};
} //end namespace block
