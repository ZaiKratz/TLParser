#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputPeer.h"

#include "../../../Types/Private/InputPeer.h"

//begin namespace block
namespace COMMON
{
class InputPeerChat : public PRIVATE::InputPeer
{
public:
	InputPeerChat();
	InputPeerChat(int32 chat_id);

	~InputPeerChat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
};
} //end namespace block
