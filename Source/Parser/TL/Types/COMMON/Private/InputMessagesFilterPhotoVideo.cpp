#include "../Public/InputMessagesFilterPhotoVideo.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterPhotoVideo::InputMessagesFilterPhotoVideo()
{
	this->_ConstructorID = 1458172132;
}
void InputMessagesFilterPhotoVideo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterPhotoVideo::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMessagesFilterPhotoVideo::~InputMessagesFilterPhotoVideo()
{
}
}//end namespace block
