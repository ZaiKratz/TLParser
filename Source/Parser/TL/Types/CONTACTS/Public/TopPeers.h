#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/TopPeerCategoryPeers.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CONTACTS
{
class TopPeers : public TLBaseObject
{
public:
	TopPeers();
	TopPeers(TArray<COMMON::TopPeerCategoryPeers*> categories, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users);

	~TopPeers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::TopPeerCategoryPeers*>  Getcategories() const
	{
		 return this->categories;
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
	TArray<COMMON::TopPeerCategoryPeers*> categories;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
};
} //end namespace block
