#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/StickerSetCovered.h"

//begin namespace block
namespace MESSAGES
{
class ArchivedStickers : public TLBaseObject
{
public:
	ArchivedStickers();
	ArchivedStickers(int32 count, TArray<COMMON::StickerSetCovered*> sets);

	~ArchivedStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getcount() const
	{
		 return this->count;
	}

	TArray<COMMON::StickerSetCovered*>  Getsets() const
	{
		 return this->sets;
	}

private:
	int32 count;
	 TArray<COMMON::StickerSetCovered*> sets;
};
} //end namespace block
