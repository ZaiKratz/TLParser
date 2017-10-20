#include "../Public/UninstallStickerSet.h"


//begin namespace block
namespace MESSAGES
{

UninstallStickerSet::UninstallStickerSet()
{
	this->_ConstructorID = -110209570;
	this->_ContentRelated = true;
}

UninstallStickerSet::UninstallStickerSet(TLBaseObject*  stickerset)
{
	this->_ConstructorID = -110209570;
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
	this->_Responded = true;
}
UninstallStickerSet::~UninstallStickerSet()
{
	if(this->stickerset)
	{
		delete this->stickerset;
	}
}
}//end namespace block
