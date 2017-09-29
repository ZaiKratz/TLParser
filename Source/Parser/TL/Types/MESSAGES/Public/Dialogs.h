#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Dialog.h"
#include "../../../Types/Common/Public/Message.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace MESSAGES
{
class Dialogs : public TLBaseObject
{
public:
	Dialogs();
	Dialogs(TArray<COMMON::Dialog*> dialogs, TArray<COMMON::Message*> messages, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users);

	~Dialogs();
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

private:
	TArray<COMMON::Dialog*> dialogs;
	 TArray<COMMON::Message*> messages;
	 TArray<COMMON::Chat*> chats;
	 TArray<COMMON::User*> users;
};
} //end namespace block
