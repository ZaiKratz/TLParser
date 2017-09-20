#include "../Public/InputNotifyUsers.h"


//begin namespace block
namespace COMMON
{

InputNotifyUsers::InputNotifyUsers()
{
	this->_ConstructorID = 390347545;
}
void InputNotifyUsers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputNotifyUsers::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputNotifyUsers::~InputNotifyUsers()
{

}
}//end namespace block
