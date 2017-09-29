#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Common/Public/WebDocument.h"
#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaInvoice : public PRIVATE::MessageMedia
{
public:
	MessageMediaInvoice();
	MessageMediaInvoice(bool shipping_address_requested, bool test, FString title, FString description, COMMON::WebDocument* photo, int32 receipt_msg_id, FString currency, unsigned long long total_amount, FString start_param);

	~MessageMediaInvoice();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetShippingAddressRequested() const
	{
		 return this->shipping_address_requested;
	}

	bool Gettest() const
	{
		 return this->test;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getdescription() const
	{
		 return this->description;
	}

	COMMON::WebDocument*  Getphoto() const
	{
		 return this->photo;
	}

	int32 GetReceiptMsgId() const
	{
		 return this->receipt_msg_id;
	}

	FString Getcurrency() const
	{
		 return this->currency;
	}

	unsigned long long GetTotalAmount() const
	{
		 return this->total_amount;
	}

	FString GetStartParam() const
	{
		 return this->start_param;
	}

private:
	bool shipping_address_requested;
	 bool test;
	 FString title;
	 FString description;
	 COMMON::WebDocument* photo;
	 int32 receipt_msg_id;
	 FString currency;
	 unsigned long long total_amount;
	 FString start_param;
};
} //end namespace block
