#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Invoice.h"
#include "../../../Types/Common/Public/DataJSON.h"
#include "../../../Types/Common/Public/PaymentRequestedInfo.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace PAYMENTS
{
class PaymentForm : public TLBaseObject
{
public:
	PaymentForm();
	PaymentForm(bool can_save_credentials, bool password_missing, int32 bot_id, COMMON::Invoice* invoice, int32 provider_id, FString url, FString native_provider, COMMON::DataJSON* native_params, COMMON::PaymentRequestedInfo* saved_info, TLBaseObject* saved_credentials, TArray<COMMON::User*> users);

	~PaymentForm();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetCanSaveCredentials() const
	{
		 return this->can_save_credentials;
	}

	bool GetPasswordMissing() const
	{
		 return this->password_missing;
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

	FString Geturl() const
	{
		 return this->url;
	}

	FString GetNativeProvider() const
	{
		 return this->native_provider;
	}

	COMMON::DataJSON*  GetNativeParams() const
	{
		 return this->native_params;
	}

	COMMON::PaymentRequestedInfo*  GetSavedInfo() const
	{
		 return this->saved_info;
	}

	TLBaseObject*  GetSavedCredentials() const
	{
		 return this->saved_credentials;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

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
	 TLBaseObject* saved_credentials;
	 TArray<COMMON::User*> users;
};
} //end namespace block
