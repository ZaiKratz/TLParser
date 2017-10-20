#include "../Public/SetStickers.h"


//begin namespace block
namespace CHANNELS
{

SetStickers::SetStickers()
{
	this->_ConstructorID = -359881479;
	this->_ContentRelated = true;
}

SetStickers::SetStickers(COMMON::InputChannel*  channel, TLBaseObject*  stickerset)
{
	this->_ConstructorID = -359881479;
	this->_ContentRelated = true;
	this->channel = channel;
	this->stickerset = stickerset;
}
void SetStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	this->stickerset->OnSend(Writer);
}


void SetStickers::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SetStickers::~SetStickers()
{
	if(this->channel)
	{
		delete this->channel;
	}
	if(this->stickerset)
	{
		delete this->stickerset;
	}
}
}//end namespace block
