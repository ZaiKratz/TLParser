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
private:
	COMMON::InputUser* user_id;
	 int32 offset;
	 unsigned long long max_id;
	 int32 limit;
	PHOTOS::Photos* result;
};
} //end namespace block
