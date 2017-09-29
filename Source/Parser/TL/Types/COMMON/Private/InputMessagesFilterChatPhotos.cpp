#include "../Public/InputMessagesFilterChatPhotos.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterChatPhotos::InputMessagesFilterChatPhotos()
{
	this->_ConstructorID = 975236280;
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
	this->_Responded = true;
}
InputMessagesFilterChatPhotos::~InputMessagesFilterChatPhotos()
{

}
}//end namespace block
