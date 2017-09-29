#include "../Public/InputMessagesFilterMusic.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterMusic::InputMessagesFilterMusic()
{
	this->_ConstructorID = 928101534;
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
	this->_Responded = true;
}
InputMessagesFilterMusic::~InputMessagesFilterMusic()
{

}
}//end namespace block
