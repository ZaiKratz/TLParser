#include "../Public/UpdateNewStickerSet.h"


//begin namespace block
namespace COMMON
{

UpdateNewStickerSet::UpdateNewStickerSet()
{
	this->_ConstructorID = -1439659416;
}

UpdateNewStickerSet::UpdateNewStickerSet(MESSAGES::StickerSet* stickerset)
{
	this->_ConstructorID = -1439659416;
	this->stickerset = stickerset;
}
void UpdateNewStickerSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->stickerset->OnSend(Writer);
}


void UpdateNewStickerSet::OnResponce(BinaryReader& Reader)
{
	stickerset = reinterpret_cast<MESSAGES::StickerSet*>(Reader.TGReadObject());
}
UpdateNewStickerSet::~UpdateNewStickerSet()
{

}
}//end namespace block
