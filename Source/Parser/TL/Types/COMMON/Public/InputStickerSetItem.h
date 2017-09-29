#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"
#include "../../../Types/Common/Public/MaskCoords.h"

//begin namespace block
namespace COMMON
{
class InputStickerSetItem : public TLBaseObject
{
public:
	InputStickerSetItem();
	InputStickerSetItem(COMMON::InputDocument* document, FString emoji, COMMON::MaskCoords* mask_coords);

	~InputStickerSetItem();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputDocument*  Getdocument() const
	{
		 return this->document;
	}

	FString Getemoji() const
	{
		 return this->emoji;
	}

	COMMON::MaskCoords*  GetMaskCoords() const
	{
		 return this->mask_coords;
	}

private:
	COMMON::InputDocument* document;
	 FString emoji;
	 COMMON::MaskCoords* mask_coords;
};
} //end namespace block
