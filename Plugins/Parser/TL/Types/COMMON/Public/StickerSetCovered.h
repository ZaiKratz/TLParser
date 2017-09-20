#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/StickerSet.h"
#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace COMMON
{
class StickerSetCovered : public TLBaseObject
{
public:
	StickerSetCovered();
	StickerSetCovered(COMMON::StickerSet* set, COMMON::Document* cover);

	~StickerSetCovered();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::StickerSet* set;
	 COMMON::Document* cover;
};
} //end namespace block
