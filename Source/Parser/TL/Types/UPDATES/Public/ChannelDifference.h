#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Message.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace UPDATES
{
class ChannelDifference : public TLBaseObject
{
public:
	ChannelDifference();
	ChannelDifference(bool final, int32 pts, int32 timeout, TArray<COMMON::Message*> new_messages, TArray<TLBaseObject*> other_updates, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users);

	~ChannelDifference();
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

	TArray<COMMON::Message*>  GetNewMessages() const
	{
		 return this->new_messages;
	}

	TArray<TLBaseObject*>  GetOtherUpdates() const
	{
		 return this->other_updates;
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
	 TArray<COMMON::Message*> new_messages;
	 TArray<TLBaseObject*> other_updates;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
};
} //end namespace block
