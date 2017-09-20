#include "../Public/RpcDropAnswer.h"


//begin namespace block
namespace COMMON
{

RpcDropAnswer::RpcDropAnswer()
{
	this->_ConstructorID = 1084744792;
	this->_ContentRelated = true;
}

RpcDropAnswer::RpcDropAnswer(unsigned long long req_msg_id)
{
	this->_ConstructorID = 1084744792;
	this->_ContentRelated = true;
	this->req_msg_id = req_msg_id;
}
void RpcDropAnswer::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->req_msg_id);
}


void RpcDropAnswer::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::RpcDropAnswer*>(Reader.TGReadObject());
}
RpcDropAnswer::~RpcDropAnswer()
{

}
}//end namespace block
