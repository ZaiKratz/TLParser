#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Message.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"
#include "../../../Types/Updates/Public/ChannelDifference.h"

//begin namespace block
namespace UPDATES
{
class ChannelDifferenceTooLong : public TLBaseObject
{
public:
	ChannelDifferenceTooLong();
	ChannelDifferenceTooLong(bool final, int32 pts, int32 timeout, int32 top_message, int32 read_inbox_max_id, int32 read_outbox_max_id, int32 unread_count, int32 unread_mentions_count, TArray<COMMON::Message*> messages, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users);

	~ChannelDifferenceTooLong();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getfinal() const
	{
		 return this->final;
	}

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 Gettimeout() const
	{
		 return this->timeout;
	}

	int32 GetTopMessage() const
	{
		 return this->top_message;
	}

	int32 GetReadInboxMaxId() const
	{
		 return this->read_inbox_max_id;
	}

	int32 GetReadOutboxMaxId() const
	{
		 return this->read_outbox_max_id;
	}

	int32 GetUnreadCount() const
	{
		 return this->unread_count;
	}

	int32 GetUnreadMentionsCount() const
	{
		 return this->unread_mentions_count;
	}

	TArray<COMMON::Message*>  Getmessages() const
	{
		 return this->messages;
	}

	TArray<COMMON::Chat*>  Getchats() const
	{
		 return this->chats;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

private:
	bool final;
	 int32 pts;
	 int32 timeout;
	 int32 top_message;
	 int32 read_inbox_max_id;
	 int32 read_outbox_max_id;
	 int32 unread_count;
	 int32 unread_mentions_count;
	 TArray<COMMON::Message*> messages;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
};
} //end namespace block
