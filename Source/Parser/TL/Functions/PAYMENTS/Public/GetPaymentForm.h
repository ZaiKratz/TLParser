#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Payments/Public/PaymentForm.h"

//begin namespace block
namespace PAYMENTS
{
class GetPaymentForm : public TLBaseObject
{
public:
	GetPaymentForm();
	GetPaymentForm(int32 msg_id);

	~GetPaymentForm();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetMsgId() const
	{
		 return this->msg_id;
	}

	PAYMENTS::PaymentForm* GetResult() const
	{
		 return this->result;
	}

private:
	int32 msg_id;
	PAYMENTS::PaymentForm* result;
};
} //end namespace block
