#include "../Public/LeaveChannel.h"


//begin namespace block
namespace CHANNELS
{

LeaveChannel::LeaveChannel()
{
	this->_ConstructorID = -1784006920;
	this->_ContentRelated = true;
}

LeaveChannel::LeaveChannel(COMMON::InputChannel* channel)
{
	this->_ConstructorID = -1784006920;
	this->_ContentRelated = true;
	this->channel = channel;
}
void LeaveChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
}


void LeaveChannel::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
LeaveChannel::~LeaveChannel()
{

}
}//end namespace block
