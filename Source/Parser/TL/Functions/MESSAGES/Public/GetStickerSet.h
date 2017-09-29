#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputStickerSet.h"
#include "../../../Types/Messages/Public/StickerSet.h"

//begin namespace block
namespace MESSAGES
{
class GetStickerSet : public TLBaseObject
{
public:
	GetStickerSet();
	GetStickerSet(PRIVATE::InputStickerSet* stickerset);

	~GetStickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::InputStickerSet*  Getstickerset() const
	{
		 return this->stickerset;
	}

	MESSAGES::StickerSet* GetResult() const
	{
		 return this->result;
	}

private:
	PRIVATE::InputStickerSet* stickerset;
	MESSAGES::StickerSet* result;
};
} //end namespace block
