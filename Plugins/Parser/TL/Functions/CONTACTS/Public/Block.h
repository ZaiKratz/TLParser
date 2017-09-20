#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"

//begin namespace block
namespace CONTACTS
{
class Block : public TLBaseObject
{
public:
	Block();
	Block(COMMON::InputUser* id);

	~Block();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputUser* id;
	bool result;
};
} //end namespace block
