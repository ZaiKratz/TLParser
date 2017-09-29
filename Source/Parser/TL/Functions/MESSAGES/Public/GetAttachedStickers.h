#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputStickeredMedia.h"
#include "../../../Types/Common/Public/StickerSetCovered.h"

//begin namespace block
namespace MESSAGES
{
class GetAttachedStickers : public TLBaseObject
{
public:
	GetAttachedStickers();
	GetAttachedStickers(PRIVATE::InputStickeredMedia* media);

	~GetAttachedStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::InputStickeredMedia*  Getmedia() const
	{
		 return this->media;
	}

	TArray<COMMON::StickerSetCovered*> GetResult() const
	{
		 return this->result;
	}

private:
	PRIVATE::InputStickeredMedia* media;
	TArray<COMMON::StickerSetCovered*> result;
};
} //end namespace block
