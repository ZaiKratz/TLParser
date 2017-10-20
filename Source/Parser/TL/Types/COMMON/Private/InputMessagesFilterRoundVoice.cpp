#include "../Public/InputMessagesFilterRoundVoice.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterRoundVoice::InputMessagesFilterRoundVoice()
{
	this->_ConstructorID = 2054952868;
}
void InputMessagesFilterRoundVoice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterRoundVoice::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMessagesFilterRoundVoice::~InputMessagesFilterRoundVoice()
{
}
}//end namespace block
