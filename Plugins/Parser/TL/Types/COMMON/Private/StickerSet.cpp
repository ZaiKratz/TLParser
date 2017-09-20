#include "../Public/StickerSet.h"


//begin namespace block
namespace COMMON
{

StickerSet::StickerSet()
{
	this->_ConstructorID = 1094398157;
}

StickerSet::StickerSet(bool installed, bool archived, bool official, bool masks, unsigned long long id, unsigned long long access_hash, FString title, FString short_name, int32 count, int32 hash)
{
	this->_ConstructorID = 1094398157;
	this->installed = installed;
	this->archived = archived;
	this->official = official;
	this->masks = masks;
	this->id = id;
	this->access_hash = access_hash;
	this->title = title;
	this->short_name = short_name;
	this->count = count;
	this->hash = hash;
}
void StickerSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!installed)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!archived)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!official)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!masks)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->short_name);
	Writer.WriteInt(this->count);
	Writer.WriteInt(this->hash);
}


void StickerSet::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		installed = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		archived = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		official = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		masks = true;
	}
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	title = Reader.TGReadString();
	short_name = Reader.TGReadString();
	count = Reader.ReadInt();
	hash = Reader.ReadInt();
}
StickerSet::~StickerSet()
{

}
}//end namespace block
