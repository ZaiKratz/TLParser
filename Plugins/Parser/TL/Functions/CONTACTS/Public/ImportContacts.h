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
private:
	TArray<PRIVATE::InputContact*> contacts;
	CONTACTS::ImportedContacts* result;
};
} //end namespace block
