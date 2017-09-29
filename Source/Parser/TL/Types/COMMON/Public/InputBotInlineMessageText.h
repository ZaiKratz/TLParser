#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

#include "../../../Types/Private/MessageEntity.h"
#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/InputBotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageText : public PRIVATE::InputBotInlineMessage
{
public:
	InputBotInlineMessageText();
	InputBotInlineMessageText(bool no_webpage, FString message, TArray<PRIVATE::MessageEntity*> entities, PRIVATE::ReplyMarkup* reply_markup);

	~InputBotInlineMessageText();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetNoWebpage() const
	{
		 return this->no_webpage;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	TArray<PRIVATE::MessageEntity*>  Getentities() const
	{
		 return this->entities;
	}

	PRIVATE::ReplyMarkup*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	bool no_webpage;
	 FString message;
	 TArray<PRIVATE::MessageEntity*> entities;
	 PRIVATE::ReplyMarkup* reply_markup;
};
} //end namespace block
