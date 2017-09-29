#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ContactBlocked.h"
#include "../../../Types/Common/Public/User.h"
#include "../../../Types/Contacts/Public/Blocked.h"

//begin namespace block
namespace CONTACTS
{
class BlockedSlice : public TLBaseObject
{
public:
	BlockedSlice();
	BlockedSlice(int32 count, TArray<COMMON::ContactBlocked*> blocked, TArray<COMMON::User*> users);

	~BlockedSlice();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getcount() const
	{
		 return this->count;
	}

	TArray<COMMON::ContactBlocked*>  Getblocked() const
	{
		 return this->blocked;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

private:
	int32 count;
	 TArray<COMMON::ContactBlocked*> blocked;
	 TArray<COMMON::User*> users;
};
} //end namespace block
