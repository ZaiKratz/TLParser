#include "../Public/InputMessagesFilterDocument.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterDocument::InputMessagesFilterDocument()
{
	this->_ConstructorID = -1629621880;
}
void InputMessagesFilterDocument::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterDocument::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMessagesFilterDocument::~InputMessagesFilterDocument()
{

}
}//end namespace block
