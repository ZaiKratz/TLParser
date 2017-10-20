#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputGeoPoint.h"

//begin namespace block
namespace COMMON
{
class InputMediaGeoPoint : public TLBaseObject
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
