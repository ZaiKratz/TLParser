#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

#include "../../../Types/Common/Public/InputGeoPoint.h"
#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageMediaGeo : public PRIVATE::InputBotInlineMessage
{
public:
	InputBotInlineMessageMediaGeo();
	InputBotInlineMessageMediaGeo(COMMON::InputGeoPoint* geo_point, PRIVATE::ReplyMarkup* reply_markup);

	~InputBotInlineMessageMediaGeo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputGeoPoint*  GetGeoPoint() const
	{
		 return this->geo_point;
	}

	PRIVATE::ReplyMarkup*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	COMMON::InputGeoPoint* geo_point;
	 PRIVATE::ReplyMarkup* reply_markup;
};
} //end namespace block
