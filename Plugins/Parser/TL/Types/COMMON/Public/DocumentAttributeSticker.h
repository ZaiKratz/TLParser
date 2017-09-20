#pragma once
#include "Engine.h"
#include "../../../Types/Private/DocumentAttribute.h"

#include "../../../Types/Private/InputStickerSet.h"
#include "../../../Types/Common/Public/MaskCoords.h"
#include "../../../Types/Private/DocumentAttribute.h"

//begin namespace block
namespace COMMON
{
class DocumentAttributeSticker : public PRIVATE::DocumentAttribute
{
public:
	DocumentAttributeSticker();
	DocumentAttributeSticker(bool mask, FString alt, PRIVATE::InputStickerSet* stickerset, COMMON::MaskCoords* mask_coords);

	~DocumentAttributeSticker();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool mask;
	 FString alt;
	 PRIVATE::InputStickerSet* stickerset;
	 COMMON::MaskCoords* mask_coords;
};
} //end namespace block
