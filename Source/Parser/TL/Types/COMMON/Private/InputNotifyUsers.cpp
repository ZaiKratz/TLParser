#include "../Public/InputNotifyUsers.h"


//begin namespace block
namespace COMMON
{

InputNotifyUsers::InputNotifyUsers()
{
	this->_ConstructorID = 423314455;
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
	this->_Responded = true;
}
InputNotifyUsers::~InputNotifyUsers()
{
}
}//end namespace block
