#include "../Public/SendMessageCancelAction.h"


//begin namespace block
namespace COMMON
{

SendMessageCancelAction::SendMessageCancelAction()
{
	this->_ConstructorID = -171417859;
}
void SendMessageCancelAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void SendMessageCancelAction::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
SendMessageCancelAction::~SendMessageCancelAction()
{

}
}//end namespace block
