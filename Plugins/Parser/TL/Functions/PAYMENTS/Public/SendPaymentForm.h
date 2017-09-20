#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPaymentCredentials.h"
#include "../../../Types/Payments/Public/PaymentResult.h"

//begin namespace block
namespace PAYMENTS
{
class SendPaymentForm : public TLBaseObject
{
public:
	SendPaymentForm();
	SendPaymentForm(int32 msg_id, FString requested_info_id, FString shipping_option_id, COMMON::InputPaymentCredentials* credentials);

	~SendPaymentForm();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 msg_id;
	 FString requested_info_id;
	 FString shipping_option_id;
	 COMMON::InputPaymentCredentials* credentials;
	PAYMENTS::PaymentResult* result;
};
} //end namespace block
