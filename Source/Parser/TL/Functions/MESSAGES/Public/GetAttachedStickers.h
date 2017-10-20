#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/StickerSetCovered.h"

//begin namespace block
namespace MESSAGES
{
class GetAttachedStickers : public TLBaseObject
{
public:
	GetAttachedStickers();
	GetAttachedStickers(TLBaseObject* media);

	~GetAttachedStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getmedia() const
	{
		 return this->media;
	}

	TArray<COMMON::StickerSetCovered*> GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* media;
	TArray<COMMON::StickerSetCovered*> result;
};
} //end namespace block
