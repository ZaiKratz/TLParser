#include "../Public/GetStickerSet.h"


//begin namespace block
namespace MESSAGES
{

GetStickerSet::GetStickerSet()
{
	this->_ConstructorID = 245963046;
	this->_ContentRelated = true;
}

GetStickerSet::GetStickerSet(PRIVATE::InputStickerSet* stickerset)
{
	this->_ConstructorID = 245963046;
	this->_ContentRelated = true;
	this->stickerset = stickerset;
}
void GetStickerSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->stickerset->OnSend(Writer);
}


void GetStickerSet::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::StickerSet*>(Reader.TGReadObject());
}
GetStickerSet::~GetStickerSet()
{

}
}//end namespace block
