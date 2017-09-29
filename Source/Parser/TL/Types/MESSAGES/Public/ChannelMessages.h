#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Message.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"
#include "../../../Types/Messages/Public/Messages.h"

//begin namespace block
namespace MESSAGES
{
class ChannelMessages : public TLBaseObject
{
public:
	ChannelMessages();
	ChannelMessages(int32 pts, int32 count, TArray<COMMON::Message*> messages, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users);

	~ChannelMessages();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 Getcount() const
	{
		 return this->count;
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
	int32 pts;
	 int32 count;
	 TArray<COMMON::Message*> messages;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
};
} //end namespace block
