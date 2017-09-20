#include "../Public/InputPeerChannel.h"


//begin namespace block
namespace COMMON
{

InputPeerChannel::InputPeerChannel()
{
	this->_ConstructorID = -122770144;
}

InputPeerChannel::InputPeerChannel(int32 channel_id, unsigned long long access_hash)
{
	this->_ConstructorID = -122770144;
	this->channel_id = channel_id;
	this->access_hash = access_hash;
}
void InputPeerChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
	Writer.WriteLong(this->access_hash);
}


void InputPeerChannel::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	access_hash = Reader.ReadLong();
}
InputPeerChannel::~InputPeerChannel()
{

}
}//end namespace block
