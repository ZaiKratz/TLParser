#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/MaskCoords.h"

//begin namespace block
namespace COMMON
{
class DocumentAttributeSticker : public TLBaseObject
{
public:
	DocumentAttributeSticker();
	DocumentAttributeSticker(bool mask, FString alt, TLBaseObject* stickerset, COMMON::MaskCoords* mask_coords);

	~DocumentAttributeSticker();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getmask() const
	{
		 return this->mask;
	}

	FString Getalt() const
	{
		 return this->alt;
	}

	TLBaseObject*  Getstickerset() const
	{
		 return this->stickerset;
	}

	COMMON::MaskCoords*  GetMaskCoords() const
	{
		 return this->mask_coords;
	}

private:
	bool mask;
	 FString alt;
	 TLBaseObject* stickerset;
	 COMMON::MaskCoords* mask_coords;
};
} //end namespace block
