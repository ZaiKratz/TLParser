#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PaymentRequestedInfo.h"
#include "../../../Types/Payments/Public/ValidatedRequestedInfo.h"

//begin namespace block
namespace PAYMENTS
{
class ValidateRequestedInfo : public TLBaseObject
{
public:
	ValidateRequestedInfo();
	ValidateRequestedInfo(bool save, int32 msg_id, COMMON::PaymentRequestedInfo* info);

	~ValidateRequestedInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool save;
	 int32 msg_id;
	 COMMON::PaymentRequestedInfo* info;
	PAYMENTS::ValidatedRequestedInfo* result;
};
} //end namespace block
