#include "../Public/UpdateProfilePhoto.h"


//begin namespace block
namespace PHOTOS
{

UpdateProfilePhoto::UpdateProfilePhoto()
{
	this->_ConstructorID = -256159406;
	this->_ContentRelated = true;
}

UpdateProfilePhoto::UpdateProfilePhoto(COMMON::InputPhoto*  id)
{
	this->_ConstructorID = -256159406;
	this->_ContentRelated = true;
	this->id = id;
}
void UpdateProfilePhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
}


void UpdateProfilePhoto::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::UserProfilePhoto*>(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateProfilePhoto::~UpdateProfilePhoto()
{

}
}//end namespace block
