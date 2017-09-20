#pragma once
#include "Engine.h"
#include "../../../Types/Private/BotInlineMessage.h"

#include "../../../Types/Common/Public/GeoPoint.h"
#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/BotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class BotInlineMessageMediaGeo : public PRIVATE::BotInlineMessage
{
public:
	BotInlineMessageMediaGeo();
	BotInlineMessageMediaGeo(COMMON::GeoPoint* geo, PRIVATE::ReplyMarkup* reply_markup);

	~BotInlineMessageMediaGeo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::GeoPoint* geo;
	 PRIVATE::ReplyMarkup* reply_markup;
};
} //end namespace block
