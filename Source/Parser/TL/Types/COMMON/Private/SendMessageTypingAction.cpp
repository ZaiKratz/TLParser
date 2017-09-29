#include "../Public/SendMessageTypingAction.h"


//begin namespace block
namespace COMMON
{

SendMessageTypingAction::SendMessageTypingAction()
{
	this->_ConstructorID = 381645902;
}
void SendMessageTypingAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void SendMessageTypingAction::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
SendMessageTypingAction::~SendMessageTypingAction()
{

}
}//end namespace block
