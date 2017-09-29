#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/User.h"
#include "../../../Types/Photos/Public/Photos.h"

//begin namespace block
namespace PHOTOS
{
class PhotosSlice : public TLBaseObject
{
public:
	PhotosSlice();
	PhotosSlice(int32 count, TArray<COMMON::Photo*> photos, TArray<COMMON::User*> users);

	~PhotosSlice();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getcount() const
	{
		 return this->count;
	}

	TArray<COMMON::Photo*>  Getphotos() const
	{
		 return this->photos;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

private:
	int32 count;
	 TArray<COMMON::Photo*> photos;
	 TArray<COMMON::User*> users;
};
} //end namespace block