#pragma once
#include "Engine.h"
#include "../../../Types/Private/Peer.h"

#include "../../../Types/Private/Peer.h"

//begin namespace block
namespace COMMON
{
class PeerUser : public PRIVATE::Peer
{
public:
	PeerUser();
	PeerUser(int32 user_id);

	~PeerUser();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

private:
	int32 user_id;
};
} //end namespace block
