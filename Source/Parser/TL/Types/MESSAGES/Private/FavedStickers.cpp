#include "../Public/FavedStickers.h"


//begin namespace block
namespace MESSAGES
{

FavedStickers::FavedStickers()
{
	this->_ConstructorID = -209768682;
}

FavedStickers::FavedStickers(int32 hash, TArray<COMMON::StickerPack*>  packs, TArray<COMMON::Document*>  stickers)
{
	this->_ConstructorID = -209768682;
	this->hash = hash;
	this->packs = packs;
	this->stickers = stickers;
}
void FavedStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->packs.Num());
	for(auto X : this->packs)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->stickers.Num());
	for(auto X : this->stickers)
	{
	X->OnSend(Writer);
	}
}


void FavedStickers::OnResponce(BinaryReader& Reader)
{
	hash = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len27623 = Reader.ReadInt();
	for(int32 i = 0; i < Len27623; i++)
	{
	auto X = reinterpret_cast<COMMON::StickerPack*>(Reader.TGReadObject());
	packs.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len13 = Reader.ReadInt();
	for(int32 i = 0; i < Len13; i++)
	{
	auto X = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	stickers.Add(X);
	}
	this->_Responded = true;
}
FavedStickers::~FavedStickers()
{
}
}//end namespace block
