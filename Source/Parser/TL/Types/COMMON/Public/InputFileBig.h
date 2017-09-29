#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputFile.h"

//begin namespace block
namespace COMMON
{
class InputFileBig : public TLBaseObject
{
public:
	InputFileBig();
	InputFileBig(unsigned long long id, int32 parts, FString name);

	~InputFileBig();
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

private:
	unsigned long long id;
	 int32 parts;
	 FString name;
};
} //end namespace block
