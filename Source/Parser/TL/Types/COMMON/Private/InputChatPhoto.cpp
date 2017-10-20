#include "../Public/InputChatPhoto.h"


//begin namespace block
namespace COMMON
{

InputChatPhoto::InputChatPhoto()
{
	this->_ConstructorID = -1991004873;
}

InputChatPhoto::InputChatPhoto(COMMON::InputPhoto*  id)
{
	this->_ConstructorID = -1991004873;
	this->id = id;
}
void InputChatPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
}


void InputChatPhoto::OnResponce(BinaryReader& Reader)
{
	id = reinterpret_cast<COMMON::InputPhoto* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputChatPhoto::~InputChatPhoto()
{
	if(this->id)
	{
		delete this->id;
	}
}
}//end namespace block
