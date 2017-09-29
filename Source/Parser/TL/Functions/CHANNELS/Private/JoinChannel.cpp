#include "../Public/JoinChannel.h"


//begin namespace block
namespace CHANNELS
{

JoinChannel::JoinChannel()
{
	this->_ConstructorID = 615851205;
	this->_ContentRelated = true;
}

JoinChannel::JoinChannel(COMMON::InputChannel*  channel)
{
	this->_ConstructorID = 615851205;
	this->_ContentRelated = true;
	this->channel = channel;
}
void JoinChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
}


void JoinChannel::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
JoinChannel::~JoinChannel()
{

}
}//end namespace block
