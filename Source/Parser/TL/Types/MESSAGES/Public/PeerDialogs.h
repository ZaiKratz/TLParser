#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Dialog.h"
#include "../../../Types/Common/Public/Message.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"
#include "../../../Types/UPDATES/Public/State.h"

//begin namespace block
namespace MESSAGES
{
class PeerDialogs : public TLBaseObject
{
public:
	PeerDialogs();
	PeerDialogs(TArray<COMMON::Dialog*> dialogs, TArray<COMMON::Message*> messages, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users, UPDATES::State* state);

	~PeerDialogs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::Dialog*>  Getdialogs() const
	{
		 return this->dialogs;
	}

	TArray<COMMON::Message*>  Getmessages() const
	{
		 return this->messages;
	}

	TArray<COMMON::Chat*>  Getchats() const
	{
		 return this->chats;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

	UPDATES::State*  Getstate() const
	{
		 return this->state;
	}

private:
	TArray<COMMON::Dialog*> dialogs;
	 TArray<COMMON::Message*> messages;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
	 UPDATES::State* state;
};
} //end namespace block
