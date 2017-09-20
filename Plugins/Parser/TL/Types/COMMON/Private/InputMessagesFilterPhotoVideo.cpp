#include "../Public/InputMessagesFilterPhotoVideo.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterPhotoVideo::InputMessagesFilterPhotoVideo()
{
	this->_ConstructorID = -453973674;
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
}
InputMessagesFilterPhotoVideo::~InputMessagesFilterPhotoVideo()
{

}
}//end namespace block
