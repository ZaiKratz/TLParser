#pragma once
#include "Engine.h"
#include "../../../Types/Private/SendMessageAction.h"

#include "../../../Types/Private/SendMessageAction.h"

//begin namespace block
namespace COMMON
{
class SendMessageGamePlayAction : public PRIVATE::SendMessageAction
{
public:
	SendMessageGamePlayAction();
	~SendMessageGamePlayAction();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
