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

	bool Getinstalled() const
	{
		 return this->installed;
	}

	bool Getarchived() const
	{
		 return this->archived;
	}

	bool Getofficial() const
	{
		 return this->official;
	}

	bool Getmasks() const
	{
		 return this->masks;
	}

	unsigned long long Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FString GetShortName() const
	{
		 return this->short_name;
	}

	int32 Getcount() const
	{
		 return this->count;
	}

	int32 Gethash() const
	{
		 return this->hash;
	}

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
