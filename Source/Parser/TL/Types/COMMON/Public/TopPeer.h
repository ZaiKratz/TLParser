#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class TopPeer : public TLBaseObject
{
public:
	TopPeer();
	TopPeer(TLBaseObject* peer, double rating);

	~TopPeer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	double Getrating() const
	{
		 return this->rating;
	}

private:
	TLBaseObject* peer;
	 double rating;
};
} //end namespace block
