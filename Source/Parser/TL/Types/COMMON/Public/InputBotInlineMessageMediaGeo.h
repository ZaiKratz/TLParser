#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputGeoPoint.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageMediaGeo : public TLBaseObject
{
public:
	InputBotInlineMessageMediaGeo();
	InputBotInlineMessageMediaGeo(COMMON::InputGeoPoint* geo_point, TLBaseObject* reply_markup);

	~InputBotInlineMessageMediaGeo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputGeoPoint*  GetGeoPoint() const
	{
		 return this->geo_point;
	}

	TLBaseObject*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	COMMON::InputGeoPoint* geo_point;
	 TLBaseObject* reply_markup;
};
} //end namespace block
