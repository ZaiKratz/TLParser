#include "../Public/DeleteChannel.h"


//begin namespace block
namespace CHANNELS
{

DeleteChannel::DeleteChannel()
{
	this->_ConstructorID = -484503104;
	this->_ContentRelated = true;
}

DeleteChannel::DeleteChannel(COMMON::InputChannel* channel)
{
	this->_ConstructorID = -484503104;
	this->_ContentRelated = true;
	this->channel = channel;
}
void DeleteChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
}


void DeleteChannel::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
DeleteChannel::~DeleteChannel()
{

}
}//end namespace block
