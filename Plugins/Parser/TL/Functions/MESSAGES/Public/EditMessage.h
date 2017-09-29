#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/MessageEntity.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class EditMessage : public TLBaseObject
{
public:
	EditMessage();
	EditMessage(bool no_webpage, PRIVATE::InputPeer* peer, int32 id, FString message, PRIVATE::ReplyMarkup* reply_markup, TArray<PRIVATE::MessageEntity*> entities);

	~EditMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetNoWebpage() const
	{
		 return this->no_webpage;
	}

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	PRIVATE::ReplyMarkup*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

	TArray<PRIVATE::MessageEntity*>  Getentities() const
	{
		 return this->entities;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	bool no_webpage;
	 PRIVATE::InputPeer* peer;
	 int32 id;
	 FString message;
	 PRIVATE::ReplyMarkup* reply_markup;
	 TArray<PRIVATE::MessageEntity*> entities;
	COMMON::Updates* result;
};
} //end namespace block
