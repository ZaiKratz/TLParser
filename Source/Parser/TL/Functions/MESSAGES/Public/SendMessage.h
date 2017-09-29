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
class SendMessage : public TLBaseObject
{
public:
	SendMessage();
	SendMessage(bool no_webpage, bool silent, bool background, bool clear_draft, PRIVATE::InputPeer* peer, int32 reply_to_msg_id, FString message, unsigned long long random_id, PRIVATE::ReplyMarkup* reply_markup, TArray<PRIVATE::MessageEntity*> entities);

	~SendMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetNoWebpage() const
	{
		 return this->no_webpage;
	}

	bool Getsilent() const
	{
		 return this->silent;
	}

	bool Getbackground() const
	{
		 return this->background;
	}

	bool GetClearDraft() const
	{
		 return this->clear_draft;
	}

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	int32 GetReplyToMsgId() const
	{
		 return this->reply_to_msg_id;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	unsigned long long GetRandomId() const
	{
		 return this->random_id;
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
	 bool silent;
	 bool background;
	 bool clear_draft;
	 PRIVATE::InputPeer* peer;
	 int32 reply_to_msg_id;
	 FString message;
	 unsigned long long random_id;
	 PRIVATE::ReplyMarkup* reply_markup;
	 TArray<PRIVATE::MessageEntity*> entities;
	COMMON::Updates* result;
};
} //end namespace block
