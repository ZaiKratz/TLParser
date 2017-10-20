#include "../Public/SendMessageGamePlayAction.h"


//begin namespace block
namespace COMMON
{

SendMessageGamePlayAction::SendMessageGamePlayAction()
{
	this->_ConstructorID = -580219064;
}
void SendMessageGamePlayAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void SendMessageGamePlayAction::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
SendMessageGamePlayAction::~SendMessageGamePlayAction()
{
}
}//end namespace block
