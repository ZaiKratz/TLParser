#include "../Public/AddStickerToSet.h"


//begin namespace block
namespace STICKERS
{

AddStickerToSet::AddStickerToSet()
{
	this->_ConstructorID = -2041315650;
	this->_ContentRelated = true;
}

AddStickerToSet::AddStickerToSet(PRIVATE::InputStickerSet*  stickerset, COMMON::InputStickerSetItem*  sticker)
{
	this->_ConstructorID = -2041315650;
	this->_ContentRelated = true;
	this->stickerset = stickerset;
	this->sticker = sticker;
}
void AddStickerToSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->stickerset->OnSend(Writer);
	this->sticker->OnSend(Writer);
}


void AddStickerToSet::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::StickerSet*>(Reader.TGReadObject());
	this->_Responded = true;
}
AddStickerToSet::~AddStickerToSet()
{

}
}//end namespace block
