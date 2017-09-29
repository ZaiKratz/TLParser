#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/StickerSetCovered.h"

//begin namespace block
namespace MESSAGES
{
class FeaturedStickers : public TLBaseObject
{
public:
	FeaturedStickers();
	FeaturedStickers(int32 hash, TArray<COMMON::StickerSetCovered*> sets, TArray<unsigned long long> unread);

	~FeaturedStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Gethash() const
	{
		 return this->hash;
	}

	TArray<COMMON::StickerSetCovered*>  Getsets() const
	{
		 return this->sets;
	}

	TArray<unsigned long long>  Getunread() const
	{
		 return this->unread;
	}

private:
	int32 hash;
	 TArray<COMMON::StickerSetCovered*> sets;
	 TArray<unsigned long long> unread;
};
} //end namespace block
