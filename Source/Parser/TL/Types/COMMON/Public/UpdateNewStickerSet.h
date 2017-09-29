#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/MESSAGES/Public/StickerSet.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateNewStickerSet : public PRIVATE::Update
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
