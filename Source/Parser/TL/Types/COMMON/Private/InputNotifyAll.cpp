#include "../Public/InputNotifyAll.h"


//begin namespace block
namespace COMMON
{

InputNotifyAll::InputNotifyAll()
{
	this->_ConstructorID = -1540769658;
}
void InputNotifyAll::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputNotifyAll::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputNotifyAll::~InputNotifyAll()
{
}
}//end namespace block
