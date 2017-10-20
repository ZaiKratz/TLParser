#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PaymentSavedCredentialsCard : public TLBaseObject
{
public:
	PaymentSavedCredentialsCard();
	PaymentSavedCredentialsCard(FString id, FString title);

	~PaymentSavedCredentialsCard();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getid() const
	{
		 return this->id;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

private:
	FString id;
	 FString title;
};
} //end namespace block
