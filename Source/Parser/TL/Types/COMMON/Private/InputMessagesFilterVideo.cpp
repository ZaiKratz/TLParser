#include "../Public/InputMessagesFilterVideo.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterVideo::InputMessagesFilterVideo()
{
	this->_ConstructorID = -1614803355;
}
void InputMessagesFilterVideo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterVideo::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMessagesFilterVideo::~InputMessagesFilterVideo()
{
}
}//end namespace block
