#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputBotInlineMessageID.h"
#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace MESSAGES
{
class EditInlineBotMessage : public TLBaseObject
{
public:
	EditInlineBotMessage();
	EditInlineBotMessage(bool no_webpage, COMMON::InputBotInlineMessageID* id, FString message, PRIVATE::ReplyMarkup* reply_markup, TArray<PRIVATE::MessageEntity*> entities);

	~EditInlineBotMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool no_webpage;
	 COMMON::InputBotInlineMessageID* id;
	 FString message;
	 PRIVATE::ReplyMarkup* reply_markup;
	 TArray<PRIVATE::MessageEntity*> entities;
	bool result;
};
} //end namespace block
