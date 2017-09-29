#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"

//begin namespace block
namespace CONTACTS
{
class DeleteContacts : public TLBaseObject
{
public:
	DeleteContacts();
	DeleteContacts(TArray<COMMON::InputUser*> id);

	~DeleteContacts();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::InputUser*>  Getid() const
	{
		 return this->id;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	TArray<COMMON::InputUser*> id;
	bool result;
};
} //end namespace block
