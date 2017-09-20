#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionChatMigrateTo : public PRIVATE::MessageAction
{
public:
	MessageActionChatMigrateTo();
	MessageActionChatMigrateTo(int32 channel_id);

	~MessageActionChatMigrateTo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 channel_id;
};
} //end namespace block
