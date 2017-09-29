#pragma once
#include "Engine.h"
#include "../../../Types/Private/BotInlineMessage.h"

#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/BotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class BotInlineMessageMediaAuto : public PRIVATE::BotInlineMessage
{
public:
	BotInlineMessageMediaAuto();
	BotInlineMessageMediaAuto(FString caption, PRIVATE::ReplyMarkup* reply_markup);

	~BotInlineMessageMediaAuto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getcaption() const
	{
		 return this->caption;
	}

	PRIVATE::ReplyMarkup*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	FString caption;
	 PRIVATE::ReplyMarkup* reply_markup;
};
} //end namespace block
