#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChatPhoto.h"

//begin namespace block
namespace COMMON
{
class InputChatPhotoEmpty : public TLBaseObject
{
public:
	InputChatPhotoEmpty();
	~InputChatPhotoEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
