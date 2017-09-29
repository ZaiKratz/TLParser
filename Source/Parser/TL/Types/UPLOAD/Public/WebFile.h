#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/FileType.h"

//begin namespace block
namespace UPLOAD
{
class WebFile : public TLBaseObject
{
public:
	WebFile();
	WebFile(int32 size, FString mime_type, PRIVATE::FileType* file_type, int32 mtime, TArray<uint8> bytes);

	~WebFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getsize() const
	{
		 return this->size;
	}

	FString GetMimeType() const
	{
		 return this->mime_type;
	}

	PRIVATE::FileType*  GetFileType() const
	{
		 return this->file_type;
	}

	int32 Getmtime() const
	{
		 return this->mtime;
	}

	TArray<uint8>  Getbytes() const
	{
		 return this->bytes;
	}

private:
	int32 size;
	 FString mime_type;
	 PRIVATE::FileType* file_type;
	 int32 mtime;
	 TArray<uint8> bytes;
};
} //end namespace block
