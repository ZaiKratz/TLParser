#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class SaveDraft : public TLBaseObject
{
public:
	SaveDraft();
	SaveDraft(bool no_webpage, int32 reply_to_msg_id, TLBaseObject* peer, FString message, TArray<TLBaseObject*> entities);

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

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	FString Getmessage() const
	{
		 return this->message;
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
	 int32 reply_to_msg_id;
	 TLBaseObject* peer;
	 FString message;
	 TArray<TLBaseObject*> entities;
	bool result;
};
} //end namespace block
