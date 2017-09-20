#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Common/Public/PaymentRequestedInfo.h"
#include "../../../Types/Common/Public/PaymentCharge.h"
#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionPaymentSentMe : public PRIVATE::MessageAction
{
public:
	MessageActionPaymentSentMe();
	MessageActionPaymentSentMe(FString currency, unsigned long long total_amount, TArray<uint8> payload, COMMON::PaymentRequestedInfo* info, FString shipping_option_id, COMMON::PaymentCharge* charge);

	~MessageActionPaymentSentMe();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString currency;
	 unsigned long long total_amount;
	 TArray<uint8> payload;
	 COMMON::PaymentRequestedInfo* info;
	 FString shipping_option_id;
	 COMMON::PaymentCharge* charge;
};
} //end namespace block
