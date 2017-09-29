#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhotoSize.h"

//begin namespace block
namespace COMMON
{
class PhotoSizeEmpty : public TLBaseObject
{
public:
	PhotoSizeEmpty();
	PhotoSizeEmpty(FString type);

	~PhotoSizeEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gettype() const
	{
		 return this->type;
	}

private:
	FString type;
};
} //end namespace block
