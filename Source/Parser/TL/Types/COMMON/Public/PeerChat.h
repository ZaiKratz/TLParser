#pragma once
#include "Engine.h"
#include "../../../Types/Private/Peer.h"

#include "../../../Types/Private/Peer.h"

//begin namespace block
namespace COMMON
{
class PeerChat : public PRIVATE::Peer
{
public:
	PeerChat();
	PeerChat(int32 chat_id);

	~PeerChat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

private:
	int32 chat_id;
};
} //end namespace block
