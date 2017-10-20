#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"
#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace COMMON
{
class UpdatesCombined : public TLBaseObject
{
public:
	UpdatesCombined();
	UpdatesCombined(TArray<TLBaseObject*> updates, TArray<COMMON::User*> users, TArray<COMMON::Chat*> chats, FDateTime date, int32 seq_start, int32 seq);

	~UpdatesCombined();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<TLBaseObject*>  Getupdates() const
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

	int32 GetSeqStart() const
	{
		 return this->seq_start;
	}

	int32 Getseq() const
	{
		 return this->seq;
	}

private:
	TArray<TLBaseObject*> updates;
	 TArray<COMMON::User*> users;
	 TArray<COMMON::Chat*> chats;
	 FDateTime date;
	 int32 seq_start;
	 int32 seq;
};
} //end namespace block
