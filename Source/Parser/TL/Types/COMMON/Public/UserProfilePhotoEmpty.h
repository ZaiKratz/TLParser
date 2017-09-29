#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/UserProfilePhoto.h"

//begin namespace block
namespace COMMON
{
class UserProfilePhotoEmpty : public TLBaseObject
{
public:
	UserProfilePhotoEmpty();
	~UserProfilePhotoEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
