#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/UserStatus.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateUserStatus : public PRIVATE::Update
{
public:
	UpdateUserStatus();
	UpdateUserStatus(int32 user_id, PRIVATE::UserStatus* status);

	~UpdateUserStatus();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 PRIVATE::UserStatus* status;
};
} //end namespace block
