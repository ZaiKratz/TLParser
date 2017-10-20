#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/GeoPoint.h"

//begin namespace block
namespace COMMON
{
class MessageMediaGeo : public TLBaseObject
{
public:
	MessageMediaGeo();
	MessageMediaGeo(COMMON::GeoPoint* geo);

	~MessageMediaGeo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::GeoPoint*  Getgeo() const
	{
		 return this->geo;
	}

private:
	COMMON::GeoPoint* geo;
};
} //end namespace block
