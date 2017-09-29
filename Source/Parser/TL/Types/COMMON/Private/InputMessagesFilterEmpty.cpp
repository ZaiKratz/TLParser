#include "../Public/InputMessagesFilterEmpty.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterEmpty::InputMessagesFilterEmpty()
{
	this->_ConstructorID = 1474492012;
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
	this->_Responded = true;
}
InputMessagesFilterEmpty::~InputMessagesFilterEmpty()
{

}
}//end namespace block
