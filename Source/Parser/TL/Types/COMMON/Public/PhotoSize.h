#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/FileLocation.h"

//begin namespace block
namespace COMMON
{
class PhotoSize : public TLBaseObject
{
public:
	PhotoSize();
	PhotoSize(FString type, COMMON::FileLocation* location, int32 w, int32 h, int32 size);

	~PhotoSize();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gettype() const
	{
		 return this->type;
	}

	COMMON::FileLocation*  Getlocation() const
	{
		 return this->location;
	}

	int32 Getw() const
	{
		 return this->w;
	}

	int32 Geth() const
	{
		 return this->h;
	}

	int32 Getsize() const
	{
		 return this->size;
	}

private:
	FString type;
	 COMMON::FileLocation* location;
	 int32 w;
	 int32 h;
	 int32 size;
};
} //end namespace block
