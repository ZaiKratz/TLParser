#pragma once
#include "Engine.h"
#include "../../../Types/Private/UserStatus.h"

#include "../../../Types/Private/UserStatus.h"

//begin namespace block
namespace COMMON
{
class UserStatusLastMonth : public PRIVATE::UserStatus
{
public:
	UserStatusLastMonth();
	~UserStatusLastMonth();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
