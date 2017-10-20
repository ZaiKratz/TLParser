#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputFile.h"
#include "../../../Types/Common/Public/InputDocument.h"

//begin namespace block
namespace COMMON
{
class InputMediaUploadedDocument : public TLBaseObject
{
public:
	InputMediaUploadedDocument();
	InputMediaUploadedDocument(COMMON::InputFile* file, COMMON::InputFile* thumb, FString mime_type, TArray<TLBaseObject*> attributes, FString caption, TArray<COMMON::InputDocument*> stickers, int32 ttl_seconds);

	~InputMediaUploadedDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputFile*  Getfile() const
	{
		 return this->file;
	}

	COMMON::InputFile*  Getthumb() const
	{
		 return this->thumb;
	}

	FString GetMimeType() const
	{
		 return this->mime_type;
	}

	TArray<TLBaseObject*>  Getattributes() const
	{
		 return this->attributes;
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
	 COMMON::InputFile* thumb;
	 FString mime_type;
	 TArray<TLBaseObject*> attributes;
	 FString caption;
	 TArray<COMMON::InputDocument*> stickers;
	 int32 ttl_seconds;
};
} //end namespace block
