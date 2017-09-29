#pragma once
#include "Engine.h"
#include "../../../Types/Private/BotInlineMessage.h"

#include "../../../Types/Common/Public/GeoPoint.h"
#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/BotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class BotInlineMessageMediaVenue : public PRIVATE::BotInlineMessage
{
public:
	BotInlineMessageMediaVenue();
	BotInlineMessageMediaVenue(COMMON::GeoPoint* geo, FString title, FString address, FString provider, FString venue_id, PRIVATE::ReplyMarkup* reply_markup);

	~BotInlineMessageMediaVenue();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::GeoPoint*  Getgeo() const
	{
		 return this->geo;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getaddress() const
	{
		 return this->address;
	}

	FString Getprovider() const
	{
		 return this->provider;
	}

	FString GetVenueId() const
	{
		 return this->venue_id;
	}

	PRIVATE::ReplyMarkup*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	COMMON::GeoPoint* geo;
	 FString title;
	 FString address;
	 FString provider;
	 FString venue_id;
	 PRIVATE::ReplyMarkup* reply_markup;
};
} //end namespace block
