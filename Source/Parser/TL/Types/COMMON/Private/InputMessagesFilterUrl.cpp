#include "../Public/InputMessagesFilterUrl.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterUrl::InputMessagesFilterUrl()
{
	this->_ConstructorID = 2129714567;
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
	this->_Responded = true;
}
InputMessagesFilterUrl::~InputMessagesFilterUrl()
{
}
}//end namespace block
