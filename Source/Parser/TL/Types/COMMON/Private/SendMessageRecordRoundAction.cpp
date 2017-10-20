#include "../Public/SendMessageRecordRoundAction.h"


//begin namespace block
namespace COMMON
{

SendMessageRecordRoundAction::SendMessageRecordRoundAction()
{
	this->_ConstructorID = -1997373508;
}
void SendMessageRecordRoundAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void SendMessageRecordRoundAction::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
SendMessageRecordRoundAction::~SendMessageRecordRoundAction()
{
}
}//end namespace block
