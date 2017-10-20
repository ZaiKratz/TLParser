#include "../Public/PeerChannel.h"


//begin namespace block
namespace COMMON
{

PeerChannel::PeerChannel()
{
	this->_ConstructorID = -1109531342;
}

PeerChannel::PeerChannel(int32 channel_id)
{
	this->_ConstructorID = -1109531342;
	this->channel_id = channel_id;
}
void PeerChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
}


void PeerChannel::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	this->_Responded = true;
}
PeerChannel::~PeerChannel()
{
}
}//end namespace block
