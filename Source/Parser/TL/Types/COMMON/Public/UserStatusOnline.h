#pragma once
#include "Engine.h"
#include "../../../Types/Private/UserStatus.h"

#include "../../../Types/Private/UserStatus.h"

//begin namespace block
namespace COMMON
{
class UserStatusOnline : public PRIVATE::UserStatus
{
public:
	UserStatusOnline();
	UserStatusOnline(FDateTime expires);

	~UserStatusOnline();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FDateTime Getexpires() const
	{
		 return this->expires;
	}

private:
	FDateTime expires;
};
} //end namespace block
