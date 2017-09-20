#include "../Public/StickerSet.h"


//begin namespace block
namespace MESSAGES
{

StickerSet::StickerSet()
{
	this->_ConstructorID = -1507587402;
}

StickerSet::StickerSet(COMMON::StickerSet* set, TArray<COMMON::StickerPack*> packs, TArray<COMMON::Document*> documents)
{
	this->_ConstructorID = -1507587402;
	this->set = set;
	this->packs = packs;
	this->documents = documents;
}
void StickerSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->set->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->packs.Num());
	for(auto X : this->packs)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->documents.Num());
	for(auto X : this->documents)
	{
	X->OnSend(Writer);
	}
}


void StickerSet::OnResponce(BinaryReader& Reader)
{
	set = reinterpret_cast<COMMON::StickerSet*>(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len32693 = Reader.ReadInt();
	for(int32 i = 0; i < Len32693; i++)
	{
	auto X = reinterpret_cast<COMMON::StickerPack*>(Reader.TGReadObject());
	packs.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len20099 = Reader.ReadInt();
	for(int32 i = 0; i < Len20099; i++)
	{
	auto X = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	documents.Add(X);
	}
}
StickerSet::~StickerSet()
{

}
}//end namespace block
