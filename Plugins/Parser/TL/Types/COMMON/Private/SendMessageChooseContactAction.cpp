#include "../Public/SendMessageChooseContactAction.h"


//begin namespace block
namespace COMMON
{

SendMessageChooseContactAction::SendMessageChooseContactAction()
{
	this->_ConstructorID = 1874627682;
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
}
SendMessageChooseContactAction::~SendMessageChooseContactAction()
{

}
}//end namespace block
