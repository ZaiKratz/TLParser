#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/Peer.h"

//begin namespace block
namespace COMMON
{
class TopPeer : public TLBaseObject
{
public:
	TopPeer();
	TopPeer(PRIVATE::Peer* peer, double rating);

	~TopPeer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::Peer*  Getpeer() const
	{
		 return this->peer;
	}

	double Getrating() const
	{
		 return this->rating;
	}

private:
	PRIVATE::Peer* peer;
	 double rating;
};
} //end namespace block
