#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionChatJoinedByLink : public PRIVATE::MessageAction
{
public:
	MessageActionChatJoinedByLink();
	MessageActionChatJoinedByLink(int32 inviter_id);

	~MessageActionChatJoinedByLink();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetInviterId() const
	{
		 return this->inviter_id;
	}

private:
	int32 inviter_id;
};
} //end namespace block
