#include "../Public/InputMessagesFilterEmpty.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterEmpty::InputMessagesFilterEmpty()
{
	this->_ConstructorID = 1828119127;
}
void InputMessagesFilterEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputMessagesFilterEmpty::~InputMessagesFilterEmpty()
{

}
}//end namespace block
