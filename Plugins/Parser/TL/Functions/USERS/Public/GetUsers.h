#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace USERS
{
class GetUsers : public TLBaseObject
{
public:
	GetUsers();
	GetUsers(TArray<COMMON::InputUser*> id);

	~GetUsers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::InputUser*> id;
	TArray<COMMON::User*> result;
};
} //end namespace block
