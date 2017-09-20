#include "../Public/SendMessageTypingAction.h"


//begin namespace block
namespace COMMON
{

SendMessageTypingAction::SendMessageTypingAction()
{
	this->_ConstructorID = 1316273942;
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
}
SendMessageTypingAction::~SendMessageTypingAction()
{

}
}//end namespace block
