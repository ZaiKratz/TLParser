#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Private/InputStickerSet.h"

//begin namespace block
namespace CHANNELS
{
class SetStickers : public TLBaseObject
{
public:
	SetStickers();
	SetStickers(COMMON::InputChannel* channel, PRIVATE::InputStickerSet* stickerset);

	~SetStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	 PRIVATE::InputStickerSet* stickerset;
	bool result;
};
} //end namespace block
