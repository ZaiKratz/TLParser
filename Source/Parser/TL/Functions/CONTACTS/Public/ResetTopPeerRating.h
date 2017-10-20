#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace CONTACTS
{
class ResetTopPeerRating : public TLBaseObject
{
public:
	ResetTopPeerRating();
	ResetTopPeerRating(TLBaseObject* category, TLBaseObject* peer);

	~ResetTopPeerRating();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getcategory() const
	{
		 return this->category;
	}

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* category;
	 TLBaseObject* peer;
	bool result;
};
} //end namespace block
