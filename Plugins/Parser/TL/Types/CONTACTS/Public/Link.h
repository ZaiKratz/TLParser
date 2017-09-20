#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/ContactLink.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CONTACTS
{
class Link : public TLBaseObject
{
public:
	Link();
	Link(PRIVATE::ContactLink* my_link, PRIVATE::ContactLink* foreign_link, COMMON::User* user);

	~Link();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::ContactLink* my_link;
	 PRIVATE::ContactLink* foreign_link;
	 COMMON::User* user;
};
} //end namespace block
