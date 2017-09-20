#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputFile.h"
#include "../../../Types/Photos/Public/Photo.h"

//begin namespace block
namespace PHOTOS
{
class UploadProfilePhoto : public TLBaseObject
{
public:
	UploadProfilePhoto();
	UploadProfilePhoto(COMMON::InputFile* file);

	~UploadProfilePhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputFile* file;
	PHOTOS::Photo* result;
};
} //end namespace block
