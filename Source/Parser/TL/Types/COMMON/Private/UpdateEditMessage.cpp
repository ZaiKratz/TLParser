#include "../Public/UpdateEditMessage.h"


//begin namespace block
namespace COMMON
{

UpdateEditMessage::UpdateEditMessage()
{
	this->_ConstructorID = -469536605;
}

UpdateEditMessage::UpdateEditMessage(COMMON::Message*  message, int32 pts, int32 pts_count)
{
	this->_ConstructorID = -469536605;
	this->message = message;
	this->pts = pts;
	this->pts_count = pts_count;
}
void UpdateEditMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->message->OnSend(Writer);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
}


void UpdateEditMessage::OnResponce(BinaryReader& Reader)
{
	message = reinterpret_cast<COMMON::Message* >(Reader.TGReadObject());
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
	this->_Responded = true;
}
UpdateEditMessage::~UpdateEditMessage()
{

}
}//end namespace block
