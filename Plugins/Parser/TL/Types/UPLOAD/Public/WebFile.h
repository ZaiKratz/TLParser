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
private:
	int32 size;
	 FString mime_type;
	 PRIVATE::FileType* file_type;
	 int32 mtime;
	 TArray<uint8> bytes;
};
} //end namespace block
