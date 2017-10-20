#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class StickerSetInstallResultSuccess : public TLBaseObject
{
public:
	StickerSetInstallResultSuccess();
	~StickerSetInstallResultSuccess();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
