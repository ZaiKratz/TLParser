#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Invoice.h"
#include "../../../Types/Common/Public/DataJSON.h"
#include "../../../Types/Common/Public/PaymentRequestedInfo.h"
#include "../../../Types/Private/PaymentSavedCredentials.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace PAYMENTS
{
class PaymentForm : public TLBaseObject
{
public:
	PaymentForm();
	PaymentForm(bool can_save_credentials, bool password_missing, int32 bot_id, COMMON::Invoice* invoice, int32 provider_id, FString url, FString native_provider, COMMON::DataJSON* native_params, COMMON::PaymentRequestedInfo* saved_info, PRIVATE::PaymentSavedCredentials* saved_credentials, TArray<COMMON::User*> users);

	~PaymentForm();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool can_save_credentials;
	 bool password_missing;
	 int32 bot_id;
	 COMMON::Invoice* invoice;
	 int32 provider_id;
	 FString url;
	 FString native_provider;
	 COMMON::DataJSON* native_params;
	 COMMON::PaymentRequestedInfo* saved_info;
	 PRIVATE::PaymentSavedCredentials* saved_credentials;
	 TArray<COMMON::User*> users;
};
} //end namespace block
