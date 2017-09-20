#include "../Public/InputMessagesFilterDocument.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterDocument::InputMessagesFilterDocument()
{
	this->_ConstructorID = -1997415010;
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
}
InputMessagesFilterDocument::~InputMessagesFilterDocument()
{

}
}//end namespace block
