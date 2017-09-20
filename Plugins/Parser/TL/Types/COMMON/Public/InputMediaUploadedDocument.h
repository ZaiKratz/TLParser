#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Common/Public/InputFile.h"
#include "../../../Types/Private/DocumentAttribute.h"
#include "../../../Types/Common/Public/InputDocument.h"
#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaUploadedDocument : public PRIVATE::InputMedia
{
public:
	InputMediaUploadedDocument();
	InputMediaUploadedDocument(COMMON::InputFile* file, COMMON::InputFile* thumb, FString mime_type, TArray<PRIVATE::DocumentAttribute*> attributes, FString caption, TArray<COMMON::InputDocument*> stickers, int32 ttl_seconds);

	~InputMediaUploadedDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputFile* file;
	 COMMON::InputFile* thumb;
	 FString mime_type;
	 TArray<PRIVATE::DocumentAttribute*> attributes;
	 FString caption;
	 TArray<COMMON::InputDocument*> stickers;
	 int32 ttl_seconds;
};
} //end namespace block
