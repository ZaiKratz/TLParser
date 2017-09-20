#include "../Public/StickerSetMultiCovered.h"


//begin namespace block
namespace COMMON
{

StickerSetMultiCovered::StickerSetMultiCovered()
{
	this->_ConstructorID = 467994420;
}

StickerSetMultiCovered::StickerSetMultiCovered(COMMON::StickerSet* set, TArray<COMMON::Document*> covers)
{
	this->_ConstructorID = 467994420;
	this->set = set;
	this->covers = covers;
}
void StickerSetMultiCovered::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->set->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->covers.Num());
	for(auto X : this->covers)
	{
	X->OnSend(Writer);
	}
}


void StickerSetMultiCovered::OnResponce(BinaryReader& Reader)
{
	set = reinterpret_cast<COMMON::StickerSet*>(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len20167 = Reader.ReadInt();
	for(int32 i = 0; i < Len20167; i++)
	{
	auto X = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	covers.Add(X);
	}
}
StickerSetMultiCovered::~StickerSetMultiCovered()
{

}
}//end namespace block
