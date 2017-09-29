#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Common/Public/GeoPoint.h"
#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaVenue : public PRIVATE::MessageMedia
{
public:
	MessageMediaVenue();
	MessageMediaVenue(COMMON::GeoPoint* geo, FString title, FString address, FString provider, FString venue_id);

	~MessageMediaVenue();
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

private:
	COMMON::GeoPoint* geo;
	 FString title;
	 FString address;
	 FString provider;
	 FString venue_id;
};
} //end namespace block
