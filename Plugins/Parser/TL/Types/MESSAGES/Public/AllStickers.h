#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/StickerSet.h"

//begin namespace block
namespace MESSAGES
{
class AllStickers : public TLBaseObject
{
public:
	AllStickers();
	AllStickers(int32 hash, TArray<COMMON::StickerSet*> sets);

	~AllStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 hash;
	 TArray<COMMON::StickerSet*> sets;
};
} //end namespace block
