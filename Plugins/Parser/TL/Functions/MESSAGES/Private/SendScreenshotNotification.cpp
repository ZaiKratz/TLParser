#include "../Public/SendScreenshotNotification.h"


//begin namespace block
namespace MESSAGES
{

SendScreenshotNotification::SendScreenshotNotification()
{
	this->_ConstructorID = 552631753;
	this->_ContentRelated = true;
}

SendScreenshotNotification::SendScreenshotNotification(PRIVATE::InputPeer* peer, int32 reply_to_msg_id, unsigned long long random_id)
{
	this->_ConstructorID = 552631753;
	this->_ContentRelated = true;
	this->peer = peer;
	this->reply_to_msg_id = reply_to_msg_id;
	this->random_id = random_id;
}
void SendScreenshotNotification::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(this->reply_to_msg_id);
	Writer.WriteLong(this->random_id);
}


void SendScreenshotNotification::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
SendScreenshotNotification::~SendScreenshotNotification()
{

}
}//end namespace block
