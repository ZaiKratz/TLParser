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
private:
	FString name;
	 FString phone;
	 FString email;
	 COMMON::PostAddress* shipping_address;
};
} //end namespace block
