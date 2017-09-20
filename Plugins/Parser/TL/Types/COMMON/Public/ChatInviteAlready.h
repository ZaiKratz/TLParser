#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/ChatInvite.h"

//begin namespace block
namespace COMMON
{
class ChatInviteAlready : public TLBaseObject
{
public:
	ChatInviteAlready();
	ChatInviteAlready(COMMON::Chat* chat);

	~ChatInviteAlready();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::Chat* chat;
};
} //end namespace block
