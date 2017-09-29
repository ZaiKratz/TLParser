#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/Peer.h"

//begin namespace block
namespace COMMON
{
class NotifyPeer : public TLBaseObject
{
public:
	NotifyPeer();
	NotifyPeer(PRIVATE::Peer* peer);

	~NotifyPeer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::Peer*  Getpeer() const
	{
		 return this->peer;
	}

private:
	PRIVATE::Peer* peer;
};
} //end namespace block
