#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Private/SendMessageAction.h"

//begin namespace block
namespace MESSAGES
{
class SetTyping : public TLBaseObject
{
public:
	SetTyping();
	SetTyping(PRIVATE::InputPeer* peer, PRIVATE::SendMessageAction* action);

	~SetTyping();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPeer* peer;
	 PRIVATE::SendMessageAction* action;
	bool result;
};
} //end namespace block
