#include "../Public/SendMessageGamePlayAction.h"


//begin namespace block
namespace COMMON
{

SendMessageGamePlayAction::SendMessageGamePlayAction()
{
	this->_ConstructorID = 1217358557;
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
}
SendMessageGamePlayAction::~SendMessageGamePlayAction()
{

}
}//end namespace block
