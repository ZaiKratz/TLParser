#include "../Public/UpdateNewStickerSet.h"


//begin namespace block
namespace COMMON
{

UpdateNewStickerSet::UpdateNewStickerSet()
{
	this->_ConstructorID = 1753886890;
}

UpdateNewStickerSet::UpdateNewStickerSet(MESSAGES::StickerSet*  stickerset)
{
	this->_ConstructorID = 1753886890;
	this->stickerset = stickerset;
}
void UpdateNewStickerSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->stickerset->OnSend(Writer);
}


void UpdateNewStickerSet::OnResponce(BinaryReader& Reader)
{
	stickerset = reinterpret_cast<MESSAGES::StickerSet* >(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateNewStickerSet::~UpdateNewStickerSet()
{

}
}//end namespace block
