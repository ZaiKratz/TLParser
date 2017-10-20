#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/GeoPoint.h"

//begin namespace block
namespace COMMON
{
class BotInlineMessageMediaGeo : public TLBaseObject
{
public:
	BotInlineMessageMediaGeo();
	BotInlineMessageMediaGeo(COMMON::GeoPoint* geo, TLBaseObject* reply_markup);

	~BotInlineMessageMediaGeo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::GeoPoint*  Getgeo() const
	{
		 return this->geo;
	}

	TLBaseObject*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	COMMON::GeoPoint* geo;
	 TLBaseObject* reply_markup;
};
} //end namespace block
