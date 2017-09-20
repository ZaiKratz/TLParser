#include "../Public/UpdateReadChannelInbox.h"


//begin namespace block
namespace COMMON
{

UpdateReadChannelInbox::UpdateReadChannelInbox()
{
	this->_ConstructorID = 2146636866;
}

UpdateReadChannelInbox::UpdateReadChannelInbox(int32 channel_id, int32 max_id)
{
	this->_ConstructorID = 2146636866;
	this->channel_id = channel_id;
	this->max_id = max_id;
}
void UpdateReadChannelInbox::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
	Writer.WriteInt(this->max_id);
}


void UpdateReadChannelInbox::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	max_id = Reader.ReadInt();
}
UpdateReadChannelInbox::~UpdateReadChannelInbox()
{

}
}//end namespace block
