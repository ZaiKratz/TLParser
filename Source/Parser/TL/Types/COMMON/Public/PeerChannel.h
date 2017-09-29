#pragma once
#include "Engine.h"
#include "../../../Types/Private/Peer.h"

#include "../../../Types/Private/Peer.h"

//begin namespace block
namespace COMMON
{
class PeerChannel : public PRIVATE::Peer
{
public:
	PeerChannel();
	PeerChannel(int32 channel_id);

	~PeerChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChannelId() const
	{
		 return this->channel_id;
	}

private:
	int32 channel_id;
};
} //end namespace block
