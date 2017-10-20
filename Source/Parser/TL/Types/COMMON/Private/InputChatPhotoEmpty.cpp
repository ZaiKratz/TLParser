#include "../Public/InputChatPhotoEmpty.h"


//begin namespace block
namespace COMMON
{

InputChatPhotoEmpty::InputChatPhotoEmpty()
{
	this->_ConstructorID = 480546647;
}
void InputChatPhotoEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputChatPhotoEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputChatPhotoEmpty::~InputChatPhotoEmpty()
{
}
}//end namespace block
