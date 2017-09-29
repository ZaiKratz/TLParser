#pragma once
#include "Engine.h"
#include "../../../Types/Private/UserStatus.h"

#include "../../../Types/Private/UserStatus.h"

//begin namespace block
namespace COMMON
{
class UserStatusRecently : public PRIVATE::UserStatus
{
public:
	UserStatusRecently();
	~UserStatusRecently();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
