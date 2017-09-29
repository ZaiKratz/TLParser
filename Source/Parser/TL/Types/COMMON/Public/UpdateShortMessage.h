#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/MessageFwdHeader.h"
#include "../../../Types/Private/MessageEntity.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace COMMON
{
class UpdateShortMessage : public TLBaseObject
{
public:
	UpdateShortMessage();
	UpdateShortMessage(bool out, bool mentioned, bool media_unread, bool silent, int32 id, int32 user_id, FString message, int32 pts, int32 pts_count, FDateTime date, COMMON::MessageFwdHeader* fwd_from, int32 via_bot_id, int32 reply_to_msg_id, TArray<PRIVATE::MessageEntity*> entities);

	~UpdateShortMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getout() const
	{
		 return this->out;
	}

	bool Getmentioned() const
	{
		 return this->mentioned;
	}

	bool GetMediaUnread() const
	{
		 return this->media_unread;
	}

	bool Getsilent() const
	{
		 return this->silent;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 GetPtsCount() const
	{
		 return this->pts_count;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	COMMON::MessageFwdHeader*  GetFwdFrom() const
	{
		 return this->fwd_from;
	}

	int32 GetViaBotId() const
	{
		 return this->via_bot_id;
	}

	int32 GetReplyToMsgId() const
	{
		 return this->reply_to_msg_id;
	}

	TArray<PRIVATE::MessageEntity*>  Getentities() const
	{
		 return this->entities;
	}

private:
	bool out;
	 bool mentioned;
	 bool media_unread;
	 bool silent;
	 int32 id;
	 int32 user_id;
	 FString message;
	 int32 pts;
	 int32 pts_count;
	 FDateTime date;
	 COMMON::MessageFwdHeader* fwd_from;
	 int32 via_bot_id;
	 int32 reply_to_msg_id;
	 TArray<PRIVATE::MessageEntity*> entities;
};
} //end namespace block
