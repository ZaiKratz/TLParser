#include "../Public/RpcAnswerDropped.h"


//begin namespace block
namespace COMMON
{

RpcAnswerDropped::RpcAnswerDropped()
{
	this->_ConstructorID = -1539647305;
}

RpcAnswerDropped::RpcAnswerDropped(unsigned long long msg_id, int32 seq_no, int32 bytes)
{
	this->_ConstructorID = -1539647305;
	this->msg_id = msg_id;
	this->seq_no = seq_no;
	this->bytes = bytes;
}
void RpcAnswerDropped::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->msg_id);
	Writer.WriteInt(this->seq_no);
	Writer.WriteInt(this->bytes);
}


void RpcAnswerDropped::OnResponce(BinaryReader& Reader)
{
	msg_id = Reader.ReadLong();
	seq_no = Reader.ReadInt();
	bytes = Reader.ReadInt();
	this->_Responded = true;
}
RpcAnswerDropped::~RpcAnswerDropped()
{
}
}//end namespace block
