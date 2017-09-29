#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LabeledPrice.h"

//begin namespace block
namespace COMMON
{
class Invoice : public TLBaseObject
{
public:
	Invoice();
	Invoice(bool test, bool name_requested, bool phone_requested, bool email_requested, bool shipping_address_requested, bool flexible, FString currency, TArray<COMMON::LabeledPrice*> prices);

	~Invoice();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Gettest() const
	{
		 return this->test;
	}

	bool GetNameRequested() const
	{
		 return this->name_requested;
	}

	bool GetPhoneRequested() const
	{
		 return this->phone_requested;
	}

	bool GetEmailRequested() const
	{
		 return this->email_requested;
	}

	bool GetShippingAddressRequested() const
	{
		 return this->shipping_address_requested;
	}

	bool Getflexible() const
	{
		 return this->flexible;
	}

	FString Getcurrency() const
	{
		 return this->currency;
	}

	TArray<COMMON::LabeledPrice*>  Getprices() const
	{
		 return this->prices;
	}

private:
	bool test;
	 bool name_requested;
	 bool phone_requested;
	 bool email_requested;
	 bool shipping_address_requested;
	 bool flexible;
	 FString currency;
	 TArray<COMMON::LabeledPrice*> prices;
};
} //end namespace block
