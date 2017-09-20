#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageMediaContact : public PRIVATE::InputBotInlineMessage
{
public:
	InputBotInlineMessageMediaContact();
	InputBotInlineMessageMediaContact(FString phone_number, FString first_name, FString last_name, PRIVATE::ReplyMarkup* reply_markup);

	~InputBotInlineMessageMediaContact();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString phone_number;
	 FString first_name;
	 FString last_name;
	 PRIVATE::ReplyMarkup* reply_markup;
};
} //end namespace block
