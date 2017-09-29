#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/Update.h"
#include "../../../Types/Common/Public/User.h"
#include "../../../Types/Common/Public/Chat.h"

//begin namespace block
namespace COMMON
{
class Updates : public TLBaseObject
{
public:
	Updates();
	Updates(TArray<PRIVATE::Update*> updates, TArray<COMMON::User*> users, TArray<COMMON::Chat*> chats, FDateTime date, int32 seq);

	~Updates();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<PRIVATE::Update*>  Getupdates() const
	{
		 return this->updates;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

	TArray<COMMON::Chat*>  Getchats() const
	{
		 return this->chats;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 Getseq() const
	{
		 return this->seq;
	}

private:
	TArray<PRIVATE::Update*> updates;
	 TArray<COMMON::User*> users;
	 TArray<COMMON::Chat*> chats;
	 FDateTime date;
	 int32 seq;
};
} //end namespace block
