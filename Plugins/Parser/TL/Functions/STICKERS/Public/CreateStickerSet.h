#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/InputStickerSetItem.h"
#include "../../../Types/Messages/Public/StickerSet.h"

//begin namespace block
namespace STICKERS
{
class CreateStickerSet : public TLBaseObject
{
public:
	CreateStickerSet();
	CreateStickerSet(bool masks, COMMON::InputUser* user_id, FString title, FString short_name, TArray<COMMON::InputStickerSetItem*> stickers);

	~CreateStickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool masks;
	 COMMON::InputUser* user_id;
	 FString title;
	 FString short_name;
	 TArray<COMMON::InputStickerSetItem*> stickers;
	MESSAGES::StickerSet* result;
};
} //end namespace block
