#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class BotInlineMessageText : public TLBaseObject
{
public:
	BotInlineMessageText();
	BotInlineMessageText(bool no_webpage, FString message, TArray<TLBaseObject*> entities, TLBaseObject* reply_markup);

	~BotInlineMessageText();
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

	TArray<TLBaseObject*>  Getentities() const
	{
		 return this->entities;
	}

	TLBaseObject*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	bool no_webpage;
	 FString message;
	 TArray<TLBaseObject*> entities;
	 TLBaseObject* reply_markup;
};
} //end namespace block
