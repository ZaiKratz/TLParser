#include "../Public/BadMsgNotification.h"


//begin namespace block
namespace COMMON
{

BadMsgNotification::BadMsgNotification()
{
	this->_ConstructorID = 301526951;
}

BadMsgNotification::BadMsgNotification(unsigned long long bad_msg_id, int32 bad_msg_seqno, int32 error_code)
{
	this->_ConstructorID = 301526951;
	this->bad_msg_id = bad_msg_id;
	this->bad_msg_seqno = bad_msg_seqno;
	this->error_code = error_code;
}
void BadMsgNotification::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->bad_msg_id);
	Writer.WriteInt(this->bad_msg_seqno);
	Writer.WriteInt(this->error_code);
}


void BadMsgNotification::OnResponce(BinaryReader& Reader)
{
	bad_msg_id = Reader.ReadLong();
	bad_msg_seqno = Reader.ReadInt();
	error_code = Reader.ReadInt();
}
BadMsgNotification::~BadMsgNotification()
{

}
}//end namespace block
