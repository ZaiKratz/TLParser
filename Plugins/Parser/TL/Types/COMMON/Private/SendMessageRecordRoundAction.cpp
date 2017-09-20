#include "../Public/SendMessageRecordRoundAction.h"


//begin namespace block
namespace COMMON
{

SendMessageRecordRoundAction::SendMessageRecordRoundAction()
{
	this->_ConstructorID = -1132465528;
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
}
SendMessageRecordRoundAction::~SendMessageRecordRoundAction()
{

}
}//end namespace block
