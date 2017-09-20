#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Common/Public/InputFile.h"
#include "../../../Types/Common/Public/InputDocument.h"
#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaUploadedPhoto : public PRIVATE::InputMedia
{
public:
	InputMediaUploadedPhoto();
	InputMediaUploadedPhoto(COMMON::InputFile* file, FString caption, TArray<COMMON::InputDocument*> stickers, int32 ttl_seconds);

	~InputMediaUploadedPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputFile* file;
	 FString caption;
	 TArray<COMMON::InputDocument*> stickers;
	 int32 ttl_seconds;
};
} //end namespace block
