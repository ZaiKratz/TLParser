#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/UserProfilePhoto.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateUserPhoto : public PRIVATE::Update
{
public:
	UpdateUserPhoto();
	UpdateUserPhoto(int32 user_id, FDateTime date, COMMON::UserProfilePhoto* photo, bool previous);

	~UpdateUserPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 FDateTime date;
	 COMMON::UserProfilePhoto* photo;
	 bool previous;
};
} //end namespace block
