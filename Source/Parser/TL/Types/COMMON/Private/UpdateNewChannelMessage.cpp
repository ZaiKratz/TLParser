#include "../Public/UpdateNewChannelMessage.h"


//begin namespace block
namespace COMMON
{

UpdateNewChannelMessage::UpdateNewChannelMessage()
{
	this->_ConstructorID = 1656358105;
}

UpdateNewChannelMessage::UpdateNewChannelMessage(COMMON::Message*  message, int32 pts, int32 pts_count)
{
	this->_ConstructorID = 1656358105;
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
	message = reinterpret_cast<COMMON::Message* >(Reader.TGReadObject());
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
	this->_Responded = true;
}
UpdateNewChannelMessage::~UpdateNewChannelMessage()
{
	if(this->message)
	{
		delete this->message;
	}
}
}//end namespace block
