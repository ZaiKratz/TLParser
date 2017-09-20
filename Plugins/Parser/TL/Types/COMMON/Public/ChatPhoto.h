#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/FileLocation.h"

//begin namespace block
namespace COMMON
{
class ChatPhoto : public TLBaseObject
{
public:
	ChatPhoto();
	ChatPhoto(COMMON::FileLocation* photo_small, COMMON::FileLocation* photo_big);

	~ChatPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::FileLocation* photo_small;
	 COMMON::FileLocation* photo_big;
};
} //end namespace block
