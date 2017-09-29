#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Message.h"
#include "../../../Types/Common/Public/EncryptedMessage.h"
#include "../../../Types/Private/Update.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"
#include "../../../Types/UPDATES/Public/State.h"

//begin namespace block
namespace UPDATES
{
class Difference : public TLBaseObject
{
public:
	Difference();
	Difference(TArray<COMMON::Message*> new_messages, TArray<COMMON::EncryptedMessage*> new_encrypted_messages, TArray<PRIVATE::Update*> other_updates, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users, UPDATES::State* state);

	~Difference();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::Message*>  GetNewMessages() const
	{
		 return this->new_messages;
	}

	TArray<COMMON::EncryptedMessage*>  GetNewEncryptedMessages() const
	{
		 return this->new_encrypted_messages;
	}

	TArray<PRIVATE::Update*>  GetOtherUpdates() const
	{
		 return this->other_updates;
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
	TArray<COMMON::Message*> new_messages;
	 TArray<COMMON::EncryptedMessage*> new_encrypted_messages;
	 TArray<PRIVATE::Update*> other_updates;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
	 UPDATES::State* state;
};
} //end namespace block
