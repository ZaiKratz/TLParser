#include "../Public/MsgDetailedInfo.h"


//begin namespace block
namespace COMMON
{

MsgDetailedInfo::MsgDetailedInfo()
{
	this->_ConstructorID = 661470918;
}

MsgDetailedInfo::MsgDetailedInfo(unsigned long long msg_id, unsigned long long answer_msg_id, int32 bytes, int32 status)
{
	this->_ConstructorID = 661470918;
	this->msg_id = msg_id;
	this->answer_msg_id = answer_msg_id;
	this->bytes = bytes;
	this->status = status;
}
void MsgDetailedInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->msg_id);
	Writer.WriteLong(this->answer_msg_id);
	Writer.WriteInt(this->bytes);
	Writer.WriteInt(this->status);
}


void MsgDetailedInfo::OnResponce(BinaryReader& Reader)
{
	msg_id = Reader.ReadLong();
	answer_msg_id = Reader.ReadLong();
	bytes = Reader.ReadInt();
	status = Reader.ReadInt();
	this->_Responded = true;
}
MsgDetailedInfo::~MsgDetailedInfo()
{

}
}//end namespace block
