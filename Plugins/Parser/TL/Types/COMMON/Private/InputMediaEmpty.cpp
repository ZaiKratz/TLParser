#include "../Public/InputMediaEmpty.h"


//begin namespace block
namespace COMMON
{

InputMediaEmpty::InputMediaEmpty()
{
	this->_ConstructorID = 2146788502;
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
}
InputMediaEmpty::~InputMediaEmpty()
{

}
}//end namespace block
