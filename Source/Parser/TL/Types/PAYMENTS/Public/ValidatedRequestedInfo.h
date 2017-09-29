#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ShippingOption.h"

//begin namespace block
namespace PAYMENTS
{
class ValidatedRequestedInfo : public TLBaseObject
{
public:
	ValidatedRequestedInfo();
	ValidatedRequestedInfo(FString id, TArray<COMMON::ShippingOption*> shipping_options);

	~ValidatedRequestedInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getid() const
	{
		 return this->id;
	}

	TArray<COMMON::ShippingOption*>  GetShippingOptions() const
	{
		 return this->shipping_options;
	}

private:
	FString id;
	 TArray<COMMON::ShippingOption*> shipping_options;
};
} //end namespace block
