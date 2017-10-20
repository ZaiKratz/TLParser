#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CONTACTS
{
class Link : public TLBaseObject
{
public:
	Link();
	Link(TLBaseObject* my_link, TLBaseObject* foreign_link, COMMON::User* user);

	~Link();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  GetMyLink() const
	{
		 return this->my_link;
	}

	TLBaseObject*  GetForeignLink() const
	{
		 return this->foreign_link;
	}

	COMMON::User*  Getuser() const
	{
		 return this->user;
	}

private:
	TLBaseObject* my_link;
	 TLBaseObject* foreign_link;
	 COMMON::User* user;
};
} //end namespace block
