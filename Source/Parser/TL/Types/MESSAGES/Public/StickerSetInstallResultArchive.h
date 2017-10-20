#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/StickerSetCovered.h"

//begin namespace block
namespace MESSAGES
{
class StickerSetInstallResultArchive : public TLBaseObject
{
public:
	StickerSetInstallResultArchive();
	StickerSetInstallResultArchive(TArray<COMMON::StickerSetCovered*> sets);

	~StickerSetInstallResultArchive();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::StickerSetCovered*>  Getsets() const
	{
		 return this->sets;
	}

private:
	TArray<COMMON::StickerSetCovered*> sets;
};
} //end namespace block
