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

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getdescription() const
	{
		 return this->description;
	}

	COMMON::InputWebDocument*  Getphoto() const
	{
		 return this->photo;
	}

	COMMON::Invoice*  Getinvoice() const
	{
		 return this->invoice;
	}

	TArray<uint8>  Getpayload() const
	{
		 return this->payload;
	}

	FString Getprovider() const
	{
		 return this->provider;
	}

	FString GetStartParam() const
	{
		 return this->start_param;
	}

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
