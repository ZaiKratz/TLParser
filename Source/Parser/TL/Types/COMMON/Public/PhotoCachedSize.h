#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/FileLocation.h"
#include "../../../Types/Common/Public/PhotoSize.h"

//begin namespace block
namespace COMMON
{
class PhotoCachedSize : public TLBaseObject
{
public:
	PhotoCachedSize();
	PhotoCachedSize(FString type, COMMON::FileLocation* location, int32 w, int32 h, TArray<uint8> bytes);

	~PhotoCachedSize();
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

	TArray<uint8>  Getbytes() const
	{
		 return this->bytes;
	}

private:
	FString type;
	 COMMON::FileLocation* location;
	 int32 w;
	 int32 h;
	 TArray<uint8> bytes;
};
} //end namespace block
