#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Common/Public/InputGeoPoint.h"
#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaGeoPoint : public PRIVATE::InputMedia
{
public:
	InputMediaGeoPoint();
	InputMediaGeoPoint(COMMON::InputGeoPoint* geo_point);

	~InputMediaGeoPoint();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputGeoPoint*  GetGeoPoint() const
	{
		 return this->geo_point;
	}

private:
	COMMON::InputGeoPoint* geo_point;
};
} //end namespace block
