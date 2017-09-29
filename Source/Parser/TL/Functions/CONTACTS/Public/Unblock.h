#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"

//begin namespace block
namespace CONTACTS
{
class Unblock : public TLBaseObject
{
public:
	Unblock();
	Unblock(COMMON::InputUser* id);

	~Unblock();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputUser*  Getid() const
	{
		 return this->id;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputUser* id;
	bool result;
};
} //end namespace block
