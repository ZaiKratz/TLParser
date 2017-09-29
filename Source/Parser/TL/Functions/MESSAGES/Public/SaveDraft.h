#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace MESSAGES
{
class SaveDraft : public TLBaseObject
{
public:
	SaveDraft();
	SaveDraft(bool no_webpage, int32 reply_to_msg_id, PRIVATE::InputPeer* peer, FString message, TArray<PRIVATE::MessageEntity*> entities);

	~SaveDraft();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetNoWebpage() const
	{
		 return this->no_webpage;
	}

	int32 GetReplyToMsgId() const
	{
		 return this->reply_to_msg_id;
	}

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	TArray<PRIVATE::MessageEntity*>  Getentities() const
	{
		 return this->entities;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool no_webpage;
	 int32 reply_to_msg_id;
	 PRIVATE::InputPeer* peer;
	 FString message;
	 TArray<PRIVATE::MessageEntity*> entities;
	bool result;
};
} //end namespace block
