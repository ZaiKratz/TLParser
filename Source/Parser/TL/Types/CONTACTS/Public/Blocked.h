#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ContactBlocked.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CONTACTS
{
class Blocked : public TLBaseObject
{
public:
	Blocked();
	Blocked(TArray<COMMON::ContactBlocked*> blocked, TArray<COMMON::User*> users);

	~Blocked();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::ContactBlocked*>  Getblocked() const
	{
		 return this->blocked;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

private:
	TArray<COMMON::ContactBlocked*> blocked;
	 TArray<COMMON::User*> users;
};
} //end namespace block
