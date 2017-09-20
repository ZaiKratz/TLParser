#include "../Public/FeaturedStickers.h"


//begin namespace block
namespace MESSAGES
{

FeaturedStickers::FeaturedStickers()
{
	this->_ConstructorID = -444031496;
}

FeaturedStickers::FeaturedStickers(int32 hash, TArray<COMMON::StickerSetCovered*> sets, TArray<unsigned long long> unread)
{
	this->_ConstructorID = -444031496;
	this->hash = hash;
	this->sets = sets;
	this->unread = unread;
}
void FeaturedStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->sets.Num());
	for(auto X : this->sets)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->unread.Num());
	for(auto X : this->unread)
	{
	Writer.WriteLong(X);
	}
}


void FeaturedStickers::OnResponce(BinaryReader& Reader)
{
	hash = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len29549 = Reader.ReadInt();
	for(int32 i = 0; i < Len29549; i++)
	{
	auto X = reinterpret_cast<COMMON::StickerSetCovered*>(Reader.TGReadObject());
	sets.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len18420 = Reader.ReadInt();
	for(int32 i = 0; i < Len18420; i++)
	{
	auto X = Reader.ReadLong();
	unread.Add(X);
	}
}
FeaturedStickers::~FeaturedStickers()
{

}
}//end namespace block
