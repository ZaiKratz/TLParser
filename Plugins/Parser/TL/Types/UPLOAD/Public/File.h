#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/FileType.h"

//begin namespace block
namespace UPLOAD
{
class File : public TLBaseObject
{
public:
	File();
	File(PRIVATE::FileType* type, int32 mtime, TArray<uint8> bytes);

	~File();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::FileType* type;
	 int32 mtime;
	 TArray<uint8> bytes;
};
} //end namespace block
