#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/TopPeerCategory.h"
#include "../../../Types/Private/InputPeer.h"

//begin namespace block
namespace CONTACTS
{
class ResetTopPeerRating : public TLBaseObject
{
public:
	ResetTopPeerRating();
	ResetTopPeerRating(PRIVATE::TopPeerCategory* category, PRIVATE::InputPeer* peer);

	~ResetTopPeerRating();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::TopPeerCategory*  Getcategory() const
	{
		 return this->category;
	}

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	PRIVATE::TopPeerCategory* category;
	 PRIVATE::InputPeer* peer;
	bool result;
};
} //end namespace block
