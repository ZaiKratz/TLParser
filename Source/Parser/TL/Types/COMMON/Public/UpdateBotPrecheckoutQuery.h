#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PaymentRequestedInfo.h"

//begin namespace block
namespace COMMON
{
class UpdateBotPrecheckoutQuery : public TLBaseObject
{
public:
	UpdateBotPrecheckoutQuery();
	UpdateBotPrecheckoutQuery(unsigned long long query_id, int32 user_id, TArray<uint8> payload, COMMON::PaymentRequestedInfo* info, FString shipping_option_id, FString currency, unsigned long long total_amount);

	~UpdateBotPrecheckoutQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetQueryId() const
	{
		 return this->query_id;
	}

	int32 GetUserId() const
	{
		 return this->user_id;
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

	FString Getcurrency() const
	{
		 return this->currency;
	}

	unsigned long long GetTotalAmount() const
	{
		 return this->total_amount;
	}

private:
	unsigned long long query_id;
	 int32 user_id;
	 TArray<uint8> payload;
	 COMMON::PaymentRequestedInfo* info;
	 FString shipping_option_id;
	 FString currency;
	 unsigned long long total_amount;
};
} //end namespace block
