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
