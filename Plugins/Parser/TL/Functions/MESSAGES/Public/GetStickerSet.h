#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputStickerSet.h"
#include "../../../Types/Messages/Public/StickerSet.h"

//begin namespace block
namespace MESSAGES
{
class GetStickerSet : public TLBaseObject
{
public:
	GetStickerSet();
	GetStickerSet(PRIVATE::InputStickerSet* stickerset);

	~GetStickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputStickerSet* stickerset;
	MESSAGES::StickerSet* result;
};
} //end namespace block
