#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Contact.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CONTACTS
{
class Contacts : public TLBaseObject
{
public:
	Contacts();
	Contacts(TArray<COMMON::Contact*> contacts, int32 saved_count, TArray<COMMON::User*> users);

	~Contacts();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::Contact*> contacts;
	 int32 saved_count;
	 TArray<COMMON::User*> users;
};
} //end namespace block
