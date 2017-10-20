#include "../Public/UpdateReadChannelInbox.h"


//begin namespace block
namespace COMMON
{

UpdateReadChannelInbox::UpdateReadChannelInbox()
{
	this->_ConstructorID = 1108669311;
}

UpdateReadChannelInbox::UpdateReadChannelInbox(int32 channel_id, int32 max_id)
{
	this->_ConstructorID = 1108669311;
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
	this->_Responded = true;
}
UpdateReadChannelInbox::~UpdateReadChannelInbox()
{
}
}//end namespace block
