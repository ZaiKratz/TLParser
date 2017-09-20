#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class StickerSet : public TLBaseObject
{
public:
	StickerSet();
	StickerSet(bool installed, bool archived, bool official, bool masks, unsigned long long id, unsigned long long access_hash, FString title, FString short_name, int32 count, int32 hash);

	~StickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool installed;
	 bool archived;
	 bool official;
	 bool masks;
	 unsigned long long id;
	 unsigned long long access_hash;
	 FString title;
	 FString short_name;
	 int32 count;
	 int32 hash;
};
} //end namespace block
