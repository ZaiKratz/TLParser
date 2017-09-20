#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/SendMessageAction.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateUserTyping : public PRIVATE::Update
{
public:
	UpdateUserTyping();
	UpdateUserTyping(int32 user_id, PRIVATE::SendMessageAction* action);

	~UpdateUserTyping();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 PRIVATE::SendMessageAction* action;
};
} //end namespace block
