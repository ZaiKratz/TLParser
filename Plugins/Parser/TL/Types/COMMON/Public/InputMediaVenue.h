#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Common/Public/InputGeoPoint.h"
#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaVenue : public PRIVATE::InputMedia
{
public:
	InputMediaVenue();
	InputMediaVenue(COMMON::InputGeoPoint* geo_point, FString title, FString address, FString provider, FString venue_id);

	~InputMediaVenue();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputGeoPoint* geo_point;
	 FString title;
	 FString address;
	 FString provider;
	 FString venue_id;
};
} //end namespace block
