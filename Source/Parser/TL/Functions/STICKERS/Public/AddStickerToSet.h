#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputStickerSetItem.h"
#include "../../../Types/Messages/Public/StickerSet.h"

//begin namespace block
namespace STICKERS
{
class AddStickerToSet : public TLBaseObject
{
public:
	AddStickerToSet();
	AddStickerToSet(TLBaseObject* stickerset, COMMON::InputStickerSetItem* sticker);

	~AddStickerToSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getstickerset() const
	{
		 return this->stickerset;
	}

	COMMON::InputStickerSetItem*  Getsticker() const
	{
		 return this->sticker;
	}

	MESSAGES::StickerSet* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* stickerset;
	 COMMON::InputStickerSetItem* sticker;
	MESSAGES::StickerSet* result;
};
} //end namespace block
