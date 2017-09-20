#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateStickerSets : public PRIVATE::Update
{
public:
	UpdateStickerSets();
	~UpdateStickerSets();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
