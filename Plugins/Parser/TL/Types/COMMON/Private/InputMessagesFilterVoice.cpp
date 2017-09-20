#include "../Public/InputMessagesFilterVoice.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterVoice::InputMessagesFilterVoice()
{
	this->_ConstructorID = -1832651440;
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
}
InputMessagesFilterVoice::~InputMessagesFilterVoice()
{

}
}//end namespace block
