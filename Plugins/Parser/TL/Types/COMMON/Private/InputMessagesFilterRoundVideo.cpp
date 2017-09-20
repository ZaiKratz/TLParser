#include "../Public/InputMessagesFilterRoundVideo.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterRoundVideo::InputMessagesFilterRoundVideo()
{
	this->_ConstructorID = 1406814645;
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
}
InputMessagesFilterRoundVideo::~InputMessagesFilterRoundVideo()
{

}
}//end namespace block
