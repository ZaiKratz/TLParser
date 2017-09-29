#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoto.h"
#include "../../../Types/Common/Public/UserProfilePhoto.h"

//begin namespace block
namespace PHOTOS
{
class UpdateProfilePhoto : public TLBaseObject
{
public:
	UpdateProfilePhoto();
	UpdateProfilePhoto(COMMON::InputPhoto* id);

	~UpdateProfilePhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputPhoto*  Getid() const
	{
		 return this->id;
	}

	COMMON::UserProfilePhoto* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputPhoto* id;
	COMMON::UserProfilePhoto* result;
};
} //end namespace block
