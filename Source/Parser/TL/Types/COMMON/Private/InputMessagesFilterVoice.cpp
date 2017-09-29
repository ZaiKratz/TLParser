#include "../Public/InputMessagesFilterVoice.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterVoice::InputMessagesFilterVoice()
{
	this->_ConstructorID = 1358283666;
}
void InputMessagesFilterVoice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterVoice::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMessagesFilterVoice::~InputMessagesFilterVoice()
{

}
}//end namespace block
