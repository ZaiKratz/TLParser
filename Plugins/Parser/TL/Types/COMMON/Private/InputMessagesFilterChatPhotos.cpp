#include "../Public/InputMessagesFilterChatPhotos.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterChatPhotos::InputMessagesFilterChatPhotos()
{
	this->_ConstructorID = -1192484806;
}
void InputMessagesFilterChatPhotos::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterChatPhotos::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputMessagesFilterChatPhotos::~InputMessagesFilterChatPhotos()
{

}
}//end namespace block
