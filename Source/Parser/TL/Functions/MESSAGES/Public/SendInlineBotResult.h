#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class SendInlineBotResult : public TLBaseObject
{
public:
	SendInlineBotResult();
	SendInlineBotResult(bool silent, bool background, bool clear_draft, PRIVATE::InputPeer* peer, int32 reply_to_msg_id, unsigned long long random_id, unsigned long long query_id, FString id);

	~SendInlineBotResult();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

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

	unsigned long long GetRandomId() const
	{
		 return this->random_id;
	}

	unsigned long long GetQueryId() const
	{
		 return this->query_id;
	}

	FString Getid() const
	{
		 return this->id;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	bool silent;
	 bool background;
	 bool clear_draft;
	 PRIVATE::InputPeer* peer;
	 int32 reply_to_msg_id;
	 unsigned long long random_id;
	 unsigned long long query_id;
	 FString id;
	COMMON::Updates* result;
};
} //end namespace block
