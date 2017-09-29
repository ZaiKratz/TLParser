#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PostAddress.h"

//begin namespace block
namespace COMMON
{
class PaymentRequestedInfo : public TLBaseObject
{
public:
	PaymentRequestedInfo();
	PaymentRequestedInfo(FString name, FString phone, FString email, COMMON::PostAddress* shipping_address);

	~PaymentRequestedInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getname() const
	{
		 return this->name;
	}

	FString Getphone() const
	{
		 return this->phone;
	}

	FString Getemail() const
	{
		 return this->email;
	}

	COMMON::PostAddress*  GetShippingAddress() const
	{
		 return this->shipping_address;
	}

private:
	FString name;
	 FString phone;
	 FString email;
	 COMMON::PostAddress* shipping_address;
};
} //end namespace block
