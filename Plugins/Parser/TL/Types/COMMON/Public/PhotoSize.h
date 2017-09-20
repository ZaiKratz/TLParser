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
private:
	FString type;
	 COMMON::FileLocation* location;
	 int32 w;
	 int32 h;
	 int32 size;
};
} //end namespace block
