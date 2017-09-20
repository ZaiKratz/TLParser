#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class StickerPack : public TLBaseObject
{
public:
	StickerPack();
	StickerPack(FString emoticon, TArray<unsigned long long> documents);

	~StickerPack();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString emoticon;
	 TArray<unsigned long long> documents;
};
} //end namespace block
