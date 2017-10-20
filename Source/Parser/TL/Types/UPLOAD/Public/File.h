#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace UPLOAD
{
class File : public TLBaseObject
{
public:
	File();
	File(TLBaseObject* type, int32 mtime, TArray<uint8> bytes);

	~File();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Gettype() const
	{
		 return this->type;
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
	TLBaseObject* type;
	 int32 mtime;
	 TArray<uint8> bytes;
};
} //end namespace block
