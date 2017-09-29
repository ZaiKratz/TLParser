#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputFile : public TLBaseObject
{
public:
	InputFile();
	InputFile(unsigned long long id, int32 parts, FString name, FString md5_checksum);

	~InputFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	int32 Getparts() const
	{
		 return this->parts;
	}

	FString Getname() const
	{
		 return this->name;
	}

	FString GetMd5Checksum() const
	{
		 return this->md5_checksum;
	}

private:
	unsigned long long id;
	 int32 parts;
	 FString name;
	 FString md5_checksum;
};
} //end namespace block
