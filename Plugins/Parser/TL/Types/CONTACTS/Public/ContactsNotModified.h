#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Contacts/Public/Contacts.h"

//begin namespace block
namespace CONTACTS
{
class ContactsNotModified : public TLBaseObject
{
public:
	ContactsNotModified();
	~ContactsNotModified();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
