#include "../Public/InstallStickerSet.h"


//begin namespace block
namespace MESSAGES
{

InstallStickerSet::InstallStickerSet()
{
	this->_ConstructorID = -946871200;
	this->_ContentRelated = true;
}

InstallStickerSet::InstallStickerSet(TLBaseObject*  stickerset, bool archived)
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
	this->result = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	this->_Responded = true;
}
InstallStickerSet::~InstallStickerSet()
{
	if(this->stickerset)
	{
		delete this->stickerset;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
