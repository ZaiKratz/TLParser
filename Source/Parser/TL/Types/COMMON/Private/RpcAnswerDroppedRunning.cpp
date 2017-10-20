#include "../Public/RpcAnswerDroppedRunning.h"


//begin namespace block
namespace COMMON
{

RpcAnswerDroppedRunning::RpcAnswerDroppedRunning()
{
	this->_ConstructorID = -847714938;
}
void RpcAnswerDroppedRunning::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void RpcAnswerDroppedRunning::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
RpcAnswerDroppedRunning::~RpcAnswerDroppedRunning()
{
}
}//end namespace block
