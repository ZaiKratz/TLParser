#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputBotInlineMessageID.h"

//begin namespace block
namespace MESSAGES
{
class EditInlineBotMessage : public TLBaseObject
{
public:
	EditInlineBotMessage();
	EditInlineBotMessage(bool no_webpage, COMMON::InputBotInlineMessageID* id, FString message, TLBaseObject* reply_markup, TArray<TLBaseObject*> entities);

	~EditInlineBotMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetNoWebpage() const
	{
		 return this->no_webpage;
	}

	COMMON::InputBotInlineMessageID*  Getid() const
	{
		 return this->id;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	TLBaseObject*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

	TArray<TLBaseObject*>  Getentities() const
	{
		 return this->entities;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool no_webpage;
	 COMMON::InputBotInlineMessageID* id;
	 FString message;
	 TLBaseObject* reply_markup;
	 TArray<TLBaseObject*> entities;
	bool result;
};
} //end namespace block
