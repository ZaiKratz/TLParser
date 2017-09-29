#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputStickerSet.h"

#include "../../../Types/Private/InputStickerSet.h"

//begin namespace block
namespace COMMON
{
class InputStickerSetEmpty : public PRIVATE::InputStickerSet
{
public:
	InputStickerSetEmpty();
	~InputStickerSetEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
