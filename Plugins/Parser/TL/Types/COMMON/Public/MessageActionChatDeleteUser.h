#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionChatDeleteUser : public PRIVATE::MessageAction
{
public:
	MessageActionChatDeleteUser();
	MessageActionChatDeleteUser(int32 user_id);

	~MessageActionChatDeleteUser();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
};
} //end namespace block
