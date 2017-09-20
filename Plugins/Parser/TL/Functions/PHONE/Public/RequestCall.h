#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/PhoneCallProtocol.h"
#include "../../../Types/Phone/Public/PhoneCall.h"

//begin namespace block
namespace PHONE
{
class RequestCall : public TLBaseObject
{
public:
	RequestCall();
	RequestCall(COMMON::InputUser* user_id, int32 random_id, TArray<uint8> g_a_hash, COMMON::PhoneCallProtocol* protocol);

	~RequestCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputUser* user_id;
	 int32 random_id;
	 TArray<uint8> g_a_hash;
	 COMMON::PhoneCallProtocol* protocol;
	PHONE::PhoneCall* result;
};
} //end namespace block
