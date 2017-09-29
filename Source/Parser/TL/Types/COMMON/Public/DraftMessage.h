#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class DraftMessage : public TLBaseObject
{
public:
	DraftMessage();
	DraftMessage(bool no_webpage, int32 reply_to_msg_id, FString message, TArray<PRIVATE::MessageEntity*> entities, FDateTime date);

	~DraftMessage();
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

	FString Getmessage() const
	{
		 return this->message;
	}

	TArray<PRIVATE::MessageEntity*>  Getentities() const
	{
		 return this->entities;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

private:
	bool no_webpage;
	 int32 reply_to_msg_id;
	 FString message;
	 TArray<PRIVATE::MessageEntity*> entities;
	 FDateTime date;
};
} //end namespace block
