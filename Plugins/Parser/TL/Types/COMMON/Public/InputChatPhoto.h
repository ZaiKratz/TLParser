#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoto.h"

//begin namespace block
namespace COMMON
{
class InputChatPhoto : public TLBaseObject
{
public:
	InputChatPhoto();
	InputChatPhoto(COMMON::InputPhoto* id);

	~InputChatPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputPhoto* id;
};
} //end namespace block
