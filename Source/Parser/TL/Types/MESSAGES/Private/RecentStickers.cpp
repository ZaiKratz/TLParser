#include "../Public/RecentStickers.h"


//begin namespace block
namespace MESSAGES
{

RecentStickers::RecentStickers()
{
	this->_ConstructorID = 1558317424;
}

RecentStickers::RecentStickers(int32 hash, TArray<COMMON::Document*>  stickers)
{
	this->_ConstructorID = 1558317424;
	this->hash = hash;
	this->stickers = stickers;
}
void RecentStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->stickers.Num());
	for(auto X : this->stickers)
	{
	X->OnSend(Writer);
	}
}


void RecentStickers::OnResponce(BinaryReader& Reader)
{
	hash = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len14191 = Reader.ReadInt();
	for(int32 i = 0; i < Len14191; i++)
	{
	auto X = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	stickers.Add(X);
	}
	this->_Responded = true;
}
RecentStickers::~RecentStickers()
{

}
}//end namespace block
