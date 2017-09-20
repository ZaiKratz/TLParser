#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputFile.h"
#include "../../../Types/Common/Public/InputChatPhoto.h"

//begin namespace block
namespace COMMON
{
class InputChatUploadedPhoto : public TLBaseObject
{
public:
	InputChatUploadedPhoto();
	InputChatUploadedPhoto(COMMON::InputFile* file);

	~InputChatUploadedPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputFile* file;
};
} //end namespace block
