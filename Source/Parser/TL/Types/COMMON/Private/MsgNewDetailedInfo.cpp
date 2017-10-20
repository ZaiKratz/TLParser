#include "../Public/MsgNewDetailedInfo.h"


//begin namespace block
namespace COMMON
{

MsgNewDetailedInfo::MsgNewDetailedInfo()
{
	this->_ConstructorID = -2137147681;
}

MsgNewDetailedInfo::MsgNewDetailedInfo(unsigned long long answer_msg_id, int32 bytes, int32 status)
{
	this->_ConstructorID = -2137147681;
	this->answer_msg_id = answer_msg_id;
	this->bytes = bytes;
	this->status = status;
}
void MsgNewDetailedInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->answer_msg_id);
	Writer.WriteInt(this->bytes);
	Writer.WriteInt(this->status);
}


void MsgNewDetailedInfo::OnResponce(BinaryReader& Reader)
{
	answer_msg_id = Reader.ReadLong();
	bytes = Reader.ReadInt();
	status = Reader.ReadInt();
	this->_Responded = true;
}
MsgNewDetailedInfo::~MsgNewDetailedInfo()
{
}
}//end namespace block
