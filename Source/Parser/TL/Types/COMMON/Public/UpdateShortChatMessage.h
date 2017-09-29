#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/MessageFwdHeader.h"
#include "../../../Types/Private/MessageEntity.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace COMMON
{
class UpdateShortChatMessage : public TLBaseObject
{
public:
	UpdateShortChatMessage();
	UpdateShortChatMessage(bool out, bool mentioned, bool media_unread, bool silent, int32 id, int32 from_id, int32 chat_id, FString message, int32 pts, int32 pts_count, FDateTime date, COMMON::MessageFwdHeader* fwd_from, int32 via_bot_id, int32 reply_to_msg_id, TArray<PRIVATE::MessageEntity*> entities);

	~UpdateShortChatMessage();
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

	int32 GetFromId() const
	{
		 return this->from_id;
	}

	int32 GetChatId() const
	{
		 return this->chat_id;
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
	 int32 from_id;
	 int32 chat_id;
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
