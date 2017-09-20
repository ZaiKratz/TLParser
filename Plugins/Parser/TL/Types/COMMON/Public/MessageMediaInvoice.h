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
