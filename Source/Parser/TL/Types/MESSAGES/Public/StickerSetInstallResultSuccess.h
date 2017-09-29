#pragma once
#include "Engine.h"

#include "../../../Types/Private/StickerSetInstallResult.h"

//begin namespace block
namespace MESSAGES
{
class StickerSetInstallResultSuccess : public PRIVATE::StickerSetInstallResult
{
public:
	StickerSetInstallResultSuccess();
	~StickerSetInstallResultSuccess();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
