#include "../Public/InputChatPhoto.h"


//begin namespace block
namespace COMMON
{

InputChatPhoto::InputChatPhoto()
{
	this->_ConstructorID = 934105993;
}

InputChatPhoto::InputChatPhoto(COMMON::InputPhoto* id)
{
	this->_ConstructorID = 934105993;
	this->id = id;
}
void InputChatPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
}


void InputChatPhoto::OnResponce(BinaryReader& Reader)
{
	id = reinterpret_cast<COMMON::InputPhoto*>(Reader.TGReadObject());
}
InputChatPhoto::~InputChatPhoto()
{

}
}//end namespace block
