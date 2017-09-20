#include "../Public/RemoveStickerFromSet.h"


//begin namespace block
namespace STICKERS
{

RemoveStickerFromSet::RemoveStickerFromSet()
{
	this->_ConstructorID = 1359967991;
	this->_ContentRelated = true;
}

RemoveStickerFromSet::RemoveStickerFromSet(COMMON::InputDocument* sticker)
{
	this->_ConstructorID = 1359967991;
	this->_ContentRelated = true;
	this->sticker = sticker;
}
void RemoveStickerFromSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->sticker->OnSend(Writer);
}


void RemoveStickerFromSet::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::StickerSet*>(Reader.TGReadObject());
}
RemoveStickerFromSet::~RemoveStickerFromSet()
{

}
}//end namespace block
