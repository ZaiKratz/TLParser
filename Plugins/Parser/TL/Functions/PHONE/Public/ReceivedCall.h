#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoneCall.h"

//begin namespace block
namespace PHONE
{
class ReceivedCall : public TLBaseObject
{
public:
	ReceivedCall();
	ReceivedCall(COMMON::InputPhoneCall* peer);

	~ReceivedCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputPhoneCall* peer;
	bool result;
};
} //end namespace block
