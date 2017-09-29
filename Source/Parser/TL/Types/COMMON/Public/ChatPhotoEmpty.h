#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatPhoto.h"

//begin namespace block
namespace COMMON
{
class ChatPhotoEmpty : public TLBaseObject
{
public:
	ChatPhotoEmpty();
	~ChatPhotoEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
