#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputContact.h"
#include "../../../Types/Contacts/Public/ImportedContacts.h"

//begin namespace block
namespace CONTACTS
{
class ImportContacts : public TLBaseObject
{
public:
	ImportContacts();
	ImportContacts(TArray<PRIVATE::InputContact*> contacts);

	~ImportContacts();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<PRIVATE::InputContact*>  Getcontacts() const
	{
		 return this->contacts;
	}

	CONTACTS::ImportedContacts* GetResult() const
	{
		 return this->result;
	}

private:
	TArray<PRIVATE::InputContact*> contacts;
	CONTACTS::ImportedContacts* result;
};
} //end namespace block
