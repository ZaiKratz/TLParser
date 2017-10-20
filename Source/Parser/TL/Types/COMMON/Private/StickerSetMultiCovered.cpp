#include "../Public/StickerSetMultiCovered.h"


//begin namespace block
namespace COMMON
{

StickerSetMultiCovered::StickerSetMultiCovered()
{
	this->_ConstructorID = 872932635;
}

StickerSetMultiCovered::StickerSetMultiCovered(COMMON::StickerSet*  set, TArray<COMMON::Document*>  covers)
{
	this->_ConstructorID = 872932635;
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
	set = reinterpret_cast<COMMON::StickerSet* >(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len23791 = Reader.ReadInt();
	for(int32 i = 0; i < Len23791; i++)
	{
	auto X = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	covers.Add(X);
	}
	this->_Responded = true;
}
StickerSetMultiCovered::~StickerSetMultiCovered()
{
	if(this->set)
	{
		delete this->set;
	}
}
}//end namespace block
