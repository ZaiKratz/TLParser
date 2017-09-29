#include "../Public/GetFullChannel.h"


//begin namespace block
namespace CHANNELS
{

GetFullChannel::GetFullChannel()
{
	this->_ConstructorID = 141781513;
	this->_ContentRelated = true;
}

GetFullChannel::GetFullChannel(COMMON::InputChannel*  channel)
{
	this->_ConstructorID = 141781513;
	this->_ContentRelated = true;
	this->channel = channel;
}
void GetFullChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
}


void GetFullChannel::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::ChatFull*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetFullChannel::~GetFullChannel()
{

}
}//end namespace block
