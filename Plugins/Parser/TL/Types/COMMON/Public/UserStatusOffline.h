#pragma once
#include "Engine.h"
#include "../../../Types/Private/UserStatus.h"

#include "../../../Types/Private/UserStatus.h"

//begin namespace block
namespace COMMON
{
class UserStatusOffline : public PRIVATE::UserStatus
{
public:
	UserStatusOffline();
	UserStatusOffline(FDateTime was_online);

	~UserStatusOffline();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FDateTime was_online;
};
} //end namespace block
