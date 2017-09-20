#include "../Public/InputMessagesFilterUrl.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterUrl::InputMessagesFilterUrl()
{
	this->_ConstructorID = -2015498114;
}
void InputMessagesFilterUrl::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterUrl::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputMessagesFilterUrl::~InputMessagesFilterUrl()
{

}
}//end namespace block
