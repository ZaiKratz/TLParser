#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace PHOTOS
{
class Photos : public TLBaseObject
{
public:
	Photos();
	Photos(TArray<COMMON::Photo*> photos, TArray<COMMON::User*> users);

	~Photos();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::Photo*> photos;
	 TArray<COMMON::User*> users;
};
} //end namespace block
