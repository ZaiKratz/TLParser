#include "../Public/InputMessagesFilterRoundVideo.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterRoundVideo::InputMessagesFilterRoundVideo()
{
	this->_ConstructorID = -1253451181;
}
void InputMessagesFilterRoundVideo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterRoundVideo::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMessagesFilterRoundVideo::~InputMessagesFilterRoundVideo()
{
}
}//end namespace block
