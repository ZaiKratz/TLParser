#include "../Public/SendMessageChooseContactAction.h"


//begin namespace block
namespace COMMON
{

SendMessageChooseContactAction::SendMessageChooseContactAction()
{
	this->_ConstructorID = 1653390447;
}
void SendMessageChooseContactAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void SendMessageChooseContactAction::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
SendMessageChooseContactAction::~SendMessageChooseContactAction()
{

}
}//end namespace block
