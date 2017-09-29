#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/StickerSet.h"
#include "../../../Types/Common/Public/StickerPack.h"
#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace MESSAGES
{
class StickerSet : public TLBaseObject
{
public:
	StickerSet();
	StickerSet(COMMON::StickerSet* set, TArray<COMMON::StickerPack*> packs, TArray<COMMON::Document*> documents);

	~StickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::StickerSet*  Getset() const
	{
		 return this->set;
	}

	TArray<COMMON::StickerPack*>  Getpacks() const
	{
		 return this->packs;
	}

	TArray<COMMON::Document*>  Getdocuments() const
	{
		 return this->documents;
	}

private:
	COMMON::StickerSet* set;
	 TArray<COMMON::StickerPack*> packs;
	 TArray<COMMON::Document*> documents;
};
} //end namespace block