#include "../Public/UninstallStickerSet.h"


//begin namespace block
namespace MESSAGES
{

UninstallStickerSet::UninstallStickerSet()
{
	this->_ConstructorID = -564826375;
	this->_ContentRelated = true;
}

UninstallStickerSet::UninstallStickerSet(PRIVATE::InputStickerSet* stickerset)
{
	this->_ConstructorID = -564826375;
	this->_ContentRelated = true;
	this->stickerset = stickerset;
}
void UninstallStickerSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->stickerset->OnSend(Writer);
}


void UninstallStickerSet::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
UninstallStickerSet::~UninstallStickerSet()
{

}
}//end namespace block
