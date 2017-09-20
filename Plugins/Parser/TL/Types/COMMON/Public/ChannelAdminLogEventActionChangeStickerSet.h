#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Private/InputStickerSet.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionChangeStickerSet : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionChangeStickerSet();
	ChannelAdminLogEventActionChangeStickerSet(PRIVATE::InputStickerSet* prev_stickerset, PRIVATE::InputStickerSet* new_stickerset);

	~ChannelAdminLogEventActionChangeStickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputStickerSet* prev_stickerset;
	 PRIVATE::InputStickerSet* new_stickerset;
};
} //end namespace block
