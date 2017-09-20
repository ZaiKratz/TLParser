#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageMediaAuto : public PRIVATE::InputBotInlineMessage
{
public:
	InputBotInlineMessageMediaAuto();
	InputBotInlineMessageMediaAuto(FString caption, PRIVATE::ReplyMarkup* reply_markup);

	~InputBotInlineMessageMediaAuto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString caption;
	 PRIVATE::ReplyMarkup* reply_markup;
};
} //end namespace block
