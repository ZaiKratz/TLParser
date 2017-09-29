#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"
#include "../../../Types/Messages/Public/StickerSet.h"

//begin namespace block
namespace STICKERS
{
class RemoveStickerFromSet : public TLBaseObject
{
public:
	RemoveStickerFromSet();
	RemoveStickerFromSet(COMMON::InputDocument* sticker);

	~RemoveStickerFromSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputDocument*  Getsticker() const
	{
		 return this->sticker;
	}

	MESSAGES::StickerSet* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputDocument* sticker;
	MESSAGES::StickerSet* result;
};
} //end namespace block