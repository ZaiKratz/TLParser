#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatFull.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace MESSAGES
{
class ChatFull : public TLBaseObject
{
public:
	ChatFull();
	ChatFull(COMMON::ChatFull* full_chat, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users);

	~ChatFull();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::ChatFull* full_chat;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
};
} //end namespace block
