#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageGame : public PRIVATE::InputBotInlineMessage
{
public:
	InputBotInlineMessageGame();
	InputBotInlineMessageGame(PRIVATE::ReplyMarkup* reply_markup);

	~InputBotInlineMessageGame();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::ReplyMarkup* reply_markup;
};
} //end namespace block
