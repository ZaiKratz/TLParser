#pragma once
#include "Engine.h"
#include "../../../Types/Private/PaymentSavedCredentials.h"

#include "../../../Types/Private/PaymentSavedCredentials.h"

//begin namespace block
namespace COMMON
{
class PaymentSavedCredentialsCard : public PRIVATE::PaymentSavedCredentials
{
public:
	PaymentSavedCredentialsCard();
	PaymentSavedCredentialsCard(FString id, FString title);

	~PaymentSavedCredentialsCard();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString id;
	 FString title;
};
} //end namespace block
