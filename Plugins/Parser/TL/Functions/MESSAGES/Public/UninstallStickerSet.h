#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputStickerSet.h"

//begin namespace block
namespace MESSAGES
{
class UninstallStickerSet : public TLBaseObject
{
public:
	UninstallStickerSet();
	UninstallStickerSet(PRIVATE::InputStickerSet* stickerset);

	~UninstallStickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputStickerSet* stickerset;
	bool result;
};
} //end namespace block
