#include "../Public/InputMessagesFilterMusic.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterMusic::InputMessagesFilterMusic()
{
	this->_ConstructorID = -1632349897;
}
void InputMessagesFilterMusic::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterMusic::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputMessagesFilterMusic::~InputMessagesFilterMusic()
{

}
}//end namespace block
