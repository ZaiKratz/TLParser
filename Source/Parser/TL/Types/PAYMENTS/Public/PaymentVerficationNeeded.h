#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Payments/Public/PaymentResult.h"

//begin namespace block
namespace PAYMENTS
{
class PaymentVerficationNeeded : public TLBaseObject
{
public:
	PaymentVerficationNeeded();
	PaymentVerficationNeeded(FString url);

	~PaymentVerficationNeeded();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Geturl() const
	{
		 return this->url;
	}

private:
	FString url;
};
} //end namespace block
