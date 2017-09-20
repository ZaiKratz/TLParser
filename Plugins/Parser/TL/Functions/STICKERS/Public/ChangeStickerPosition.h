#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"
#include "../../../Types/Messages/Public/StickerSet.h"

//begin namespace block
namespace STICKERS
{
class ChangeStickerPosition : public TLBaseObject
{
public:
	ChangeStickerPosition();
	ChangeStickerPosition(COMMON::InputDocument* sticker, int32 position);

	~ChangeStickerPosition();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputDocument* sticker;
	 int32 position;
	MESSAGES::StickerSet* result;
};
} //end namespace block
