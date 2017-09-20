#include "../Public/StickerSetCovered.h"


//begin namespace block
namespace COMMON
{

StickerSetCovered::StickerSetCovered()
{
	this->_ConstructorID = -760934300;
}

StickerSetCovered::StickerSetCovered(COMMON::StickerSet* set, COMMON::Document* cover)
{
	this->_ConstructorID = -760934300;
	this->set = set;
	this->cover = cover;
}
void StickerSetCovered::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->set->OnSend(Writer);
	this->cover->OnSend(Writer);
}


void StickerSetCovered::OnResponce(BinaryReader& Reader)
{
	set = reinterpret_cast<COMMON::StickerSet*>(Reader.TGReadObject());
	cover = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
}
StickerSetCovered::~StickerSetCovered()
{

}
}//end namespace block
