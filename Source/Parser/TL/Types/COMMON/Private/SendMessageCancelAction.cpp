#include "../Public/SendMessageCancelAction.h"


//begin namespace block
namespace COMMON
{

SendMessageCancelAction::SendMessageCancelAction()
{
	this->_ConstructorID = -44119819;
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
	this->_Responded = true;
}
SendMessageCancelAction::~SendMessageCancelAction()
{

}
}//end namespace block
