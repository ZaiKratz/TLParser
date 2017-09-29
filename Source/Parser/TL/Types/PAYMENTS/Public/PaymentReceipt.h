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

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 GetBotId() const
	{
		 return this->bot_id;
	}

	COMMON::Invoice*  Getinvoice() const
	{
		 return this->invoice;
	}

	int32 GetProviderId() const
	{
		 return this->provider_id;
	}

	COMMON::PaymentRequestedInfo*  Getinfo() const
	{
		 return this->info;
	}

	COMMON::ShippingOption*  Getshipping() const
	{
		 return this->shipping;
	}

	FString Getcurrency() const
	{
		 return this->currency;
	}

	unsigned long long GetTotalAmount() const
	{
		 return this->total_amount;
	}

	FString GetCredentialsTitle() const
	{
		 return this->credentials_title;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

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
