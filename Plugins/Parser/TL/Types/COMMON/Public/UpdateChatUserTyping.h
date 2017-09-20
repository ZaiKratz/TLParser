#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/SendMessageAction.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChatUserTyping : public PRIVATE::Update
{
public:
	UpdateChatUserTyping();
	UpdateChatUserTyping(int32 chat_id, int32 user_id, PRIVATE::SendMessageAction* action);

	~UpdateChatUserTyping();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	 int32 user_id;
	 PRIVATE::SendMessageAction* action;
};
} //end namespace block
