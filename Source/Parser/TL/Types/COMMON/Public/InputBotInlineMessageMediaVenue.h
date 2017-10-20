#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputGeoPoint.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageMediaVenue : public TLBaseObject
{
public:
	InputBotInlineMessageMediaVenue();
	InputBotInlineMessageMediaVenue(COMMON::InputGeoPoint* geo_point, FString title, FString address, FString provider, FString venue_id, TLBaseObject* reply_markup);

	~InputBotInlineMessageMediaVenue();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputGeoPoint*  GetGeoPoint() const
	{
		 return this->geo_point;
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

	TLBaseObject*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	COMMON::InputGeoPoint* geo_point;
	 FString title;
	 FString address;
	 FString provider;
	 FString venue_id;
	 TLBaseObject* reply_markup;
};
} //end namespace block
