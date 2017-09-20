#include "../Public/InputMessagesFilterRoundVoice.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterRoundVoice::InputMessagesFilterRoundVoice()
{
	this->_ConstructorID = -1541964678;
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
}
InputMessagesFilterRoundVoice::~InputMessagesFilterRoundVoice()
{

}
}//end namespace block
