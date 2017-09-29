#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/Peer.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CONTACTS
{
class ResolvedPeer : public TLBaseObject
{
public:
	ResolvedPeer();
	ResolvedPeer(PRIVATE::Peer* peer, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users);

	~ResolvedPeer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::Peer*  Getpeer() const
	{
		 return this->peer;
	}

	TArray<COMMON::Chat*>  Getchats() const
	{
		 return this->chats;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

private:
	PRIVATE::Peer* peer;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
};
} //end namespace block
