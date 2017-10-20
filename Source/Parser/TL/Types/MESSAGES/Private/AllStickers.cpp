#include "../Public/AllStickers.h"


//begin namespace block
namespace MESSAGES
{

AllStickers::AllStickers()
{
	this->_ConstructorID = -302170017;
}

AllStickers::AllStickers(int32 hash, TArray<COMMON::StickerSet*>  sets)
{
	this->_ConstructorID = -302170017;
	this->hash = hash;
	this->sets = sets;
}
void AllStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->sets.Num());
	for(auto X : this->sets)
	{
	X->OnSend(Writer);
	}
}


void AllStickers::OnResponce(BinaryReader& Reader)
{
	hash = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len12071 = Reader.ReadInt();
	for(int32 i = 0; i < Len12071; i++)
	{
	auto X = reinterpret_cast<COMMON::StickerSet*>(Reader.TGReadObject());
	sets.Add(X);
	}
	this->_Responded = true;
}
AllStickers::~AllStickers()
{
}
}//end namespace block
