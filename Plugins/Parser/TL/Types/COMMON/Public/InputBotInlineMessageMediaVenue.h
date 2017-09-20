#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

#include "../../../Types/Common/Public/InputGeoPoint.h"
#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageMediaVenue : public PRIVATE::InputBotInlineMessage
{
public:
	InputBotInlineMessageMediaVenue();
	InputBotInlineMessageMediaVenue(COMMON::InputGeoPoint* geo_point, FString title, FString address, FString provider, FString venue_id, PRIVATE::ReplyMarkup* reply_markup);

	~InputBotInlineMessageMediaVenue();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputGeoPoint* geo_point;
	 FString title;
	 FString address;
	 FString provider;
	 FString venue_id;
	 PRIVATE::ReplyMarkup* reply_markup;
};
} //end namespace block
