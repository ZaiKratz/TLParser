#include "../Public/UpdateChannel.h"


//begin namespace block
namespace COMMON
{

UpdateChannel::UpdateChannel()
{
	this->_ConstructorID = -1227598250;
}

UpdateChannel::UpdateChannel(int32 channel_id)
{
	this->_ConstructorID = -1227598250;
	this->channel_id = channel_id;
}
void UpdateChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
}


void UpdateChannel::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	this->_Responded = true;
}
UpdateChannel::~UpdateChannel()
{

}
}//end namespace block
