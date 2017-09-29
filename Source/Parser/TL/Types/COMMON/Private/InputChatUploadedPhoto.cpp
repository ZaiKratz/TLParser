#include "../Public/InputChatUploadedPhoto.h"


//begin namespace block
namespace COMMON
{

InputChatUploadedPhoto::InputChatUploadedPhoto()
{
	this->_ConstructorID = -1837345356;
}

InputChatUploadedPhoto::InputChatUploadedPhoto(COMMON::InputFile*  file)
{
	this->_ConstructorID = -1837345356;
	this->file = file;
}
void InputChatUploadedPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->file->OnSend(Writer);
}


void InputChatUploadedPhoto::OnResponce(BinaryReader& Reader)
{
	file = reinterpret_cast<COMMON::InputFile* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputChatUploadedPhoto::~InputChatUploadedPhoto()
{

}
}//end namespace block
