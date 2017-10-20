#include "../Public/ChangeStickerPosition.h"


//begin namespace block
namespace STICKERS
{

ChangeStickerPosition::ChangeStickerPosition()
{
	this->_ConstructorID = -4795190;
	this->_ContentRelated = true;
}

ChangeStickerPosition::ChangeStickerPosition(COMMON::InputDocument*  sticker, int32 position)
{
	this->_ConstructorID = -4795190;
	this->_ContentRelated = true;
	this->sticker = sticker;
	this->position = position;
}
void ChangeStickerPosition::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->sticker->OnSend(Writer);
	Writer.WriteInt(this->position);
}


void ChangeStickerPosition::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::StickerSet*>(Reader.TGReadObject());
	this->_Responded = true;
}
ChangeStickerPosition::~ChangeStickerPosition()
{
	if(this->sticker)
	{
		delete this->sticker;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
