#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Message.h"
#include "../../../Types/Private/Update.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace UPDATES
{
class ChannelDifference : public TLBaseObject
{
public:
	ChannelDifference();
	ChannelDifference(bool final, int32 pts, int32 timeout, TArray<COMMON::Message*> new_messages, TArray<PRIVATE::Update*> other_updates, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users);

	~ChannelDifference();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool final;
	 int32 pts;
	 int32 timeout;
	 TArray<COMMON::Message*> new_messages;
	 TArray<PRIVATE::Update*> other_updates;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
};
} //end namespace block
