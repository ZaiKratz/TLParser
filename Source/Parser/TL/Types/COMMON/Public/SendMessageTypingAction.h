#pragma once
#include "Engine.h"
#include "../../../Types/Private/SendMessageAction.h"

#include "../../../Types/Private/SendMessageAction.h"

//begin namespace block
namespace COMMON
{
class SendMessageTypingAction : public PRIVATE::SendMessageAction
{
public:
	SendMessageTypingAction();
	~SendMessageTypingAction();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
