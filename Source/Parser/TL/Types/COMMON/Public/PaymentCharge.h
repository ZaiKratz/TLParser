#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PaymentCharge : public TLBaseObject
{
public:
	PaymentCharge();
	PaymentCharge(FString id, FString provider_charge_id);

	~PaymentCharge();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getid() const
	{
		 return this->id;
	}

	FString GetProviderChargeId() const
	{
		 return this->provider_charge_id;
	}

private:
	FString id;
	 FString provider_charge_id;
};
} //end namespace block
