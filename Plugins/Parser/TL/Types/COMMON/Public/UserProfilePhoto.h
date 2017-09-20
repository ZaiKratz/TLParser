#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/FileLocation.h"

//begin namespace block
namespace COMMON
{
class UserProfilePhoto : public TLBaseObject
{
public:
	UserProfilePhoto();
	UserProfilePhoto(unsigned long long photo_id, COMMON::FileLocation* photo_small, COMMON::FileLocation* photo_big);

	~UserProfilePhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long photo_id;
	 COMMON::FileLocation* photo_small;
	 COMMON::FileLocation* photo_big;
};
} //end namespace block
