#include "../Public/RpcAnswerUnknown.h"


//begin namespace block
namespace COMMON
{

RpcAnswerUnknown::RpcAnswerUnknown()
{
	this->_ConstructorID = 1859332702;
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
}
RpcAnswerUnknown::~RpcAnswerUnknown()
{

}
}//end namespace block
