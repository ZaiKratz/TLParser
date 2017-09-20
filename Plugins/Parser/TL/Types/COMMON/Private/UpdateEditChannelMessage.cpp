#include "../Public/UpdateEditChannelMessage.h"


//begin namespace block
namespace COMMON
{

UpdateEditChannelMessage::UpdateEditChannelMessage()
{
	this->_ConstructorID = -145932517;
}

UpdateEditChannelMessage::UpdateEditChannelMessage(COMMON::Message* message, int32 pts, int32 pts_count)
{
	this->_ConstructorID = -145932517;
	this->message = message;
	this->pts = pts;
	this->pts_count = pts_count;
}
void UpdateEditChannelMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->message->OnSend(Writer);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
}


void UpdateEditChannelMessage::OnResponce(BinaryReader& Reader)
{
	message = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
}
UpdateEditChannelMessage::~UpdateEditChannelMessage()
{

}
}//end namespace block
