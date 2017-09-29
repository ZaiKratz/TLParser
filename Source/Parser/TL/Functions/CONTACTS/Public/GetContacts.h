#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Contacts/Public/Contacts.h"

//begin namespace block
namespace CONTACTS
{
class GetContacts : public TLBaseObject
{
public:
	GetContacts();
	GetContacts(int32 hash);

	~GetContacts();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Gethash() const
	{
		 return this->hash;
	}

	CONTACTS::Contacts* GetResult() const
	{
		 return this->result;
	}

private:
	int32 hash;
	CONTACTS::Contacts* result;
};
} //end namespace block
