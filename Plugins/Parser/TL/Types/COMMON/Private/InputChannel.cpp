#include "../Public/InputChannel.h"


//begin namespace block
namespace COMMON
{

InputChannel::InputChannel()
{
	this->_ConstructorID = 779217839;
}

InputChannel::InputChannel(int32 channel_id, unsigned long long access_hash)
{
	this->_ConstructorID = 779217839;
	this->channel_id = channel_id;
	this->access_hash = access_hash;
}
void InputChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
	Writer.WriteLong(this->access_hash);
}


void InputChannel::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	access_hash = Reader.ReadLong();
}
InputChannel::~InputChannel()
{

}
}//end namespace block
