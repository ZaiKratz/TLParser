#include "../Public/InputChatUploadedPhoto.h"


//begin namespace block
namespace COMMON
{

InputChatUploadedPhoto::InputChatUploadedPhoto()
{
	this->_ConstructorID = -1269465966;
}

InputChatUploadedPhoto::InputChatUploadedPhoto(COMMON::InputFile* file)
{
	this->_ConstructorID = -1269465966;
	this->file = file;
}
void InputChatUploadedPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->file->OnSend(Writer);
}


void InputChatUploadedPhoto::OnResponce(BinaryReader& Reader)
{
	file = reinterpret_cast<COMMON::InputFile*>(Reader.TGReadObject());
}
InputChatUploadedPhoto::~InputChatUploadedPhoto()
{

}
}//end namespace block
