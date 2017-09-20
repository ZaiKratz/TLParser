#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace PHOTOS
{
class Photo : public TLBaseObject
{
public:
	Photo();
	Photo(COMMON::Photo* photo, TArray<COMMON::User*> users);

	~Photo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::Photo* photo;
	 TArray<COMMON::User*> users;
};
} //end namespace block
