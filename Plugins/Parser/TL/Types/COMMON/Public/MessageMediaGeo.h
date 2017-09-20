#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Common/Public/GeoPoint.h"
#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaGeo : public PRIVATE::MessageMedia
{
public:
	MessageMediaGeo();
	MessageMediaGeo(COMMON::GeoPoint* geo);

	~MessageMediaGeo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::GeoPoint* geo;
};
} //end namespace block
