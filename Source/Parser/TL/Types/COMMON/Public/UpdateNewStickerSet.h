#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/MESSAGES/Public/StickerSet.h"

//begin namespace block
namespace COMMON
{
class UpdateNewStickerSet : public TLBaseObject
{
public:
	UpdateNewStickerSet();
	UpdateNewStickerSet(MESSAGES::StickerSet* stickerset);

	~UpdateNewStickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	MESSAGES::StickerSet*  Getstickerset() const
	{
		 return this->stickerset;
	}

private:
	MESSAGES::StickerSet* stickerset;
};
} //end namespace block
