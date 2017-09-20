#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Contacts/Public/Link.h"

//begin namespace block
namespace CONTACTS
{
class DeleteContact : public TLBaseObject
{
public:
	DeleteContact();
	DeleteContact(COMMON::InputUser* id);

	~DeleteContact();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputUser* id;
	CONTACTS::Link* result;
};
} //end namespace block
