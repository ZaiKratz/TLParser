#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputFile.h"
#include "../../../Types/Common/Public/InputDocument.h"

//begin namespace block
namespace COMMON
{
class InputMediaUploadedPhoto : public TLBaseObject
{
public:
	InputMediaUploadedPhoto();
	InputMediaUploadedPhoto(COMMON::InputFile* file, FString caption, TArray<COMMON::InputDocument*> stickers, int32 ttl_seconds);

	~InputMediaUploadedPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputFile*  Getfile() const
	{
		 return this->file;
	}

	FString Getcaption() const
	{
		 return this->caption;
	}

	TArray<COMMON::InputDocument*>  Getstickers() const
	{
		 return this->stickers;
	}

	int32 GetTtlSeconds() const
	{
		 return this->ttl_seconds;
	}

private:
	COMMON::InputFile* file;
	 FString caption;
	 TArray<COMMON::InputDocument*> stickers;
	 int32 ttl_seconds;
};
} //end namespace block
