#include "../Public/UploadProfilePhoto.h"


//begin namespace block
namespace PHOTOS
{

UploadProfilePhoto::UploadProfilePhoto()
{
	this->_ConstructorID = -1732234673;
	this->_ContentRelated = true;
}

UploadProfilePhoto::UploadProfilePhoto(COMMON::InputFile* file)
{
	this->_ConstructorID = -1732234673;
	this->_ContentRelated = true;
	this->file = file;
}
void UploadProfilePhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->file->OnSend(Writer);
}


void UploadProfilePhoto::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PHOTOS::Photo*>(Reader.TGReadObject());
}
UploadProfilePhoto::~UploadProfilePhoto()
{

}
}//end namespace block
