#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Invoice.h"
#include "../../../Types/Common/Public/PaymentRequestedInfo.h"
#include "../../../Types/Common/Public/ShippingOption.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace PAYMENTS
{
class PaymentReceipt : public TLBaseObject
{
public:
	PaymentReceipt();
	PaymentReceipt(FDateTime date, int32 bot_id, COMMON::Invoice* invoice, int32 provider_id, COMMON::PaymentRequestedInfo* info, COMMON::ShippingOption* shipping, FString currency, unsigned long long total_amount, FString credentials_title, TArray<COMMON::User*> users);

	~PaymentReceipt();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FDateTime date;
	 int32 bot_id;
	 COMMON::Invoice* invoice;
	 int32 provider_id;
	 COMMON::PaymentRequestedInfo* info;
	 COMMON::ShippingOption* shipping;
	 FString currency;
	 unsigned long long total_amount;
	 FString credentials_title;
	 TArray<COMMON::User*> users;
};
} //end namespace block
