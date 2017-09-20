#include "../Public/UpdateNewChannelMessage.h"


//begin namespace block
namespace COMMON
{

UpdateNewChannelMessage::UpdateNewChannelMessage()
{
	this->_ConstructorID = -654001566;
}

UpdateNewChannelMessage::UpdateNewChannelMessage(COMMON::Message* message, int32 pts, int32 pts_count)
{
	this->_ConstructorID = -654001566;
	this->message = message;
	this->pts = pts;
	this->pts_count = pts_count;
}
void UpdateNewChannelMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->message->OnSend(Writer);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
}


void UpdateNewChannelMessage::OnResponce(BinaryReader& Reader)
{
	message = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
}
UpdateNewChannelMessage::~UpdateNewChannelMessage()
{

}
}//end namespace block
