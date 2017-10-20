#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PaymentRequestedInfo.h"
#include "../../../Types/Common/Public/PaymentCharge.h"

//begin namespace block
namespace COMMON
{
class MessageActionPaymentSentMe : public TLBaseObject
{
public:
	MessageActionPaymentSentMe();
	MessageActionPaymentSentMe(FString currency, unsigned long long total_amount, TArray<uint8> payload, COMMON::PaymentRequestedInfo* info, FString shipping_option_id, COMMON::PaymentCharge* charge);

	~MessageActionPaymentSentMe();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getcurrency() const
	{
		 return this->currency;
	}

	unsigned long long GetTotalAmount() const
	{
		 return this->total_amount;
	}

	TArray<uint8>  Getpayload() const
	{
		 return this->payload;
	}

	COMMON::PaymentRequestedInfo*  Getinfo() const
	{
		 return this->info;
	}

	FString GetShippingOptionId() const
	{
		 return this->shipping_option_id;
	}

	COMMON::PaymentCharge*  Getcharge() const
	{
		 return this->charge;
	}

private:
	FString currency;
	 unsigned long long total_amount;
	 TArray<uint8> payload;
	 COMMON::PaymentRequestedInfo* info;
	 FString shipping_option_id;
	 COMMON::PaymentCharge* charge;
};
} //end namespace block
