#include "../Public/UpdateNewMessage.h"


//begin namespace block
namespace COMMON
{

UpdateNewMessage::UpdateNewMessage()
{
	this->_ConstructorID = 522914557;
}

UpdateNewMessage::UpdateNewMessage(COMMON::Message*  message, int32 pts, int32 pts_count)
{
	this->_ConstructorID = 522914557;
	this->message = message;
	this->pts = pts;
	this->pts_count = pts_count;
}
void UpdateNewMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->message->OnSend(Writer);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
}


void UpdateNewMessage::OnResponce(BinaryReader& Reader)
{
	message = reinterpret_cast<COMMON::Message* >(Reader.TGReadObject());
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
	this->_Responded = true;
}
UpdateNewMessage::~UpdateNewMessage()
{
	if(this->message)
	{
		delete this->message;
	}
}
}//end namespace block
