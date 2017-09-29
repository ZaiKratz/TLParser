#include "../Public/InstallStickerSet.h"


//begin namespace block
namespace MESSAGES
{

InstallStickerSet::InstallStickerSet()
{
	this->_ConstructorID = -946871200;
	this->_ContentRelated = true;
}

InstallStickerSet::InstallStickerSet(PRIVATE::InputStickerSet*  stickerset, bool archived)
{
	this->_ConstructorID = -946871200;
	this->_ContentRelated = true;
	this->stickerset = stickerset;
	this->archived = archived;
}
void InstallStickerSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->stickerset->OnSend(Writer);
	Writer.WriteBool(this->archived);
}


void InstallStickerSet::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PRIVATE::StickerSetInstallResult*>(Reader.TGReadObject());
	this->_Responded = true;
}
InstallStickerSet::~InstallStickerSet()
{

}
}//end namespace block
