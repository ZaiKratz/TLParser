#include "../Public/UpdateEditChannelMessage.h"


//begin namespace block
namespace COMMON
{

UpdateEditChannelMessage::UpdateEditChannelMessage()
{
	this->_ConstructorID = 457133559;
}

UpdateEditChannelMessage::UpdateEditChannelMessage(COMMON::Message*  message, int32 pts, int32 pts_count)
{
	this->_ConstructorID = 457133559;
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
	message = reinterpret_cast<COMMON::Message* >(Reader.TGReadObject());
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
	this->_Responded = true;
}
UpdateEditChannelMessage::~UpdateEditChannelMessage()
{
	if(this->message)
	{
		delete this->message;
	}
}
}//end namespace block
