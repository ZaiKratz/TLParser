#include "../Public/InputNotifyAll.h"


//begin namespace block
namespace COMMON
{

InputNotifyAll::InputNotifyAll()
{
	this->_ConstructorID = -2034751068;
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
}
InputNotifyAll::~InputNotifyAll()
{

}
}//end namespace block
