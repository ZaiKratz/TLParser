#include "../Public/RpcAnswerDroppedRunning.h"


//begin namespace block
namespace COMMON
{

RpcAnswerDroppedRunning::RpcAnswerDroppedRunning()
{
	this->_ConstructorID = -2031781683;
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
}
RpcAnswerDroppedRunning::~RpcAnswerDroppedRunning()
{

}
}//end namespace block
