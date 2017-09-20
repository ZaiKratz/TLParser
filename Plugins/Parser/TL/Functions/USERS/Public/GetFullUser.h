#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/UserFull.h"

//begin namespace block
namespace USERS
{
class GetFullUser : public TLBaseObject
{
public:
	GetFullUser();
	GetFullUser(COMMON::InputUser* id);

	~GetFullUser();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputUser* id;
	COMMON::UserFull* result;
};
} //end namespace block
