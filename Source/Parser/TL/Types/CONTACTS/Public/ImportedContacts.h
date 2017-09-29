#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ImportedContact.h"
#include "../../../Types/Common/Public/PopularContact.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CONTACTS
{
class ImportedContacts : public TLBaseObject
{
public:
	ImportedContacts();
	ImportedContacts(TArray<COMMON::ImportedContact*> imported, TArray<COMMON::PopularContact*> popular_invites, TArray<unsigned long long> retry_contacts, TArray<COMMON::User*> users);

	~ImportedContacts();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::ImportedContact*>  Getimported() const
	{
		 return this->imported;
	}

	TArray<COMMON::PopularContact*>  GetPopularInvites() const
	{
		 return this->popular_invites;
	}

	TArray<unsigned long long>  GetRetryContacts() const
	{
		 return this->retry_contacts;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

private:
	TArray<COMMON::ImportedContact*> imported;
	 TArray<COMMON::PopularContact*> popular_invites;
	 TArray<unsigned long long> retry_contacts;
	 TArray<COMMON::User*> users;
};
} //end namespace block
