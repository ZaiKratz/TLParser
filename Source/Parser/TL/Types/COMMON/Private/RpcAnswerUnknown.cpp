#include "../Public/RpcAnswerUnknown.h"


//begin namespace block
namespace COMMON
{

RpcAnswerUnknown::RpcAnswerUnknown()
{
	this->_ConstructorID = 1579864942;
}
void RpcAnswerUnknown::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void RpcAnswerUnknown::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
RpcAnswerUnknown::~RpcAnswerUnknown()
{

}
}//end namespace block
