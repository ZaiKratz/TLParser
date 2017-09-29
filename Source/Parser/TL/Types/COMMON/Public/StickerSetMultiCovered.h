#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/StickerSet.h"
#include "../../../Types/Common/Public/Document.h"
#include "../../../Types/Common/Public/StickerSetCovered.h"

//begin namespace block
namespace COMMON
{
class StickerSetMultiCovered : public TLBaseObject
{
public:
	StickerSetMultiCovered();
	StickerSetMultiCovered(COMMON::StickerSet* set, TArray<COMMON::Document*> covers);

	~StickerSetMultiCovered();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::StickerSet*  Getset() const
	{
		 return this->set;
	}

	TArray<COMMON::Document*>  Getcovers() const
	{
		 return this->covers;
	}

private:
	COMMON::StickerSet* set;
	 TArray<COMMON::Document*> covers;
};
} //end namespace block
