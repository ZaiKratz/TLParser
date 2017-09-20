#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/PaymentRequestedInfo.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateBotPrecheckoutQuery : public PRIVATE::Update
{
public:
	UpdateBotPrecheckoutQuery();
	UpdateBotPrecheckoutQuery(unsigned long long query_id, int32 user_id, TArray<uint8> payload, COMMON::PaymentRequestedInfo* info, FString shipping_option_id, FString currency, unsigned long long total_amount);

	~UpdateBotPrecheckoutQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
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
