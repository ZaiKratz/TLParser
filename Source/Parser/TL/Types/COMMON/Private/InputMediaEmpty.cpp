#include "../Public/InputMediaEmpty.h"


//begin namespace block
namespace COMMON
{

InputMediaEmpty::InputMediaEmpty()
{
	this->_ConstructorID = -1771768449;
}
void InputMediaEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMediaEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMediaEmpty::~InputMediaEmpty()
{
}
}//end namespace block
