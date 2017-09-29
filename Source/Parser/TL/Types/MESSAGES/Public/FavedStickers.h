#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/StickerPack.h"
#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace MESSAGES
{
class FavedStickers : public TLBaseObject
{
public:
	FavedStickers();
	FavedStickers(int32 hash, TArray<COMMON::StickerPack*> packs, TArray<COMMON::Document*> stickers);

	~FavedStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Gethash() const
	{
		 return this->hash;
	}

	TArray<COMMON::StickerPack*>  Getpacks() const
	{
		 return this->packs;
	}

	TArray<COMMON::Document*>  Getstickers() const
	{
		 return this->stickers;
	}

private:
	int32 hash;
	 TArray<COMMON::StickerPack*> packs;
	 TArray<COMMON::Document*> stickers;
};
} //end namespace block
