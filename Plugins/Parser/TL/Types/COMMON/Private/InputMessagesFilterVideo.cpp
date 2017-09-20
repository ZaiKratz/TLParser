#include "../Public/InputMessagesFilterVideo.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterVideo::InputMessagesFilterVideo()
{
	this->_ConstructorID = 1695465631;
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
}
InputMessagesFilterVideo::~InputMessagesFilterVideo()
{

}
}//end namespace block
