#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Contacts/Public/ImportedContacts.h"

//begin namespace block
namespace CONTACTS
{
class ImportContacts : public TLBaseObject
{
public:
	ImportContacts();
	ImportContacts(TArray<TLBaseObject*> contacts);

	~ImportContacts();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<TLBaseObject*>  Getcontacts() const
	{
		 return this->contacts;
	}

	CONTACTS::ImportedContacts* GetResult() const
	{
		 return this->result;
	}

private:
	TArray<TLBaseObject*> contacts;
	CONTACTS::ImportedContacts* result;
};
} //end namespace block
