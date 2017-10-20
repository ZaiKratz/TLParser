#include "../Public/UpdateChannelPinnedMessage.h"


//begin namespace block
namespace COMMON
{

UpdateChannelPinnedMessage::UpdateChannelPinnedMessage()
{
	this->_ConstructorID = -1738988427;
}

UpdateChannelPinnedMessage::UpdateChannelPinnedMessage(int32 channel_id, int32 id)
{
	this->_ConstructorID = -1738988427;
	this->channel_id = channel_id;
	this->id = id;
}
void UpdateChannelPinnedMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
	Writer.WriteInt(this->id);
}


void UpdateChannelPinnedMessage::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	id = Reader.ReadInt();
	this->_Responded = true;
}
UpdateChannelPinnedMessage::~UpdateChannelPinnedMessage()
{
}
}//end namespace block
