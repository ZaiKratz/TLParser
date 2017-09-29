#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Payments/Public/PaymentReceipt.h"

//begin namespace block
namespace PAYMENTS
{
class GetPaymentReceipt : public TLBaseObject
{
public:
	GetPaymentReceipt();
	GetPaymentReceipt(int32 msg_id);

	~GetPaymentReceipt();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetMsgId() const
	{
		 return this->msg_id;
	}

	PAYMENTS::PaymentReceipt* GetResult() const
	{
		 return this->result;
	}

private:
	int32 msg_id;
	PAYMENTS::PaymentReceipt* result;
};
} //end namespace block
