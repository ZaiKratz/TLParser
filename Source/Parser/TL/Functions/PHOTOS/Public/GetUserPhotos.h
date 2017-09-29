#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Photos/Public/Photos.h"

//begin namespace block
namespace PHOTOS
{
class GetUserPhotos : public TLBaseObject
{
public:
	GetUserPhotos();
	GetUserPhotos(COMMON::InputUser* user_id, int32 offset, unsigned long long max_id, int32 limit);

	~GetUserPhotos();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputUser*  GetUserId() const
	{
		 return this->user_id;
	}

	int32 Getoffset() const
	{
		 return this->offset;
	}

	unsigned long long GetMaxId() const
	{
		 return this->max_id;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	PHOTOS::Photos* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputUser* user_id;
	 int32 offset;
	 unsigned long long max_id;
	 int32 limit;
	PHOTOS::Photos* result;
};
} //end namespace block
