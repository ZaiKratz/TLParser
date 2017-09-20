#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Common/Public/InputWebDocument.h"
#include "../../../Types/Common/Public/Invoice.h"
#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaInvoice : public PRIVATE::InputMedia
{
public:
	InputMediaInvoice();
	InputMediaInvoice(FString title, FString description, COMMON::InputWebDocument* photo, COMMON::Invoice* invoice, TArray<uint8> payload, FString provider, FString start_param);

	~InputMediaInvoice();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString title;
	 FString description;
	 COMMON::InputWebDocument* photo;
	 COMMON::Invoice* invoice;
	 TArray<uint8> payload;
	 FString provider;
	 FString start_param;
};
} //end namespace block
