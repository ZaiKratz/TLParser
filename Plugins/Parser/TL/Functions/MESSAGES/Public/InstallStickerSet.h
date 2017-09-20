#pragma once
#include "Engine.h"

#include "../../../Types/Private/InputStickerSet.h"
#include "../../../Types/Private/StickerSetInstallResult.h"

//begin namespace block
namespace MESSAGES
{
class InstallStickerSet : public PRIVATE::StickerSetInstallResult
{
public:
	InstallStickerSet();
	InstallStickerSet(PRIVATE::InputStickerSet* stickerset, bool archived);

	~InstallStickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputStickerSet* stickerset;
	 bool archived;
	PRIVATE::StickerSetInstallResult* result;
};
} //end namespace block
