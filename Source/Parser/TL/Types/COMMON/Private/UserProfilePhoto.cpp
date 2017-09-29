#include "../Public/UserProfilePhoto.h"


//begin namespace block
namespace COMMON
{

UserProfilePhoto::UserProfilePhoto()
{
	this->_ConstructorID = -715532088;
}

UserProfilePhoto::UserProfilePhoto(unsigned long long photo_id, COMMON::FileLocation*  photo_small, COMMON::FileLocation*  photo_big)
{
	this->_ConstructorID = -715532088;
	this->photo_id = photo_id;
	this->photo_small = photo_small;
	this->photo_big = photo_big;
}
void UserProfilePhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->photo_id);
	this->photo_small->OnSend(Writer);
	this->photo_big->OnSend(Writer);
}


void UserProfilePhoto::OnResponce(BinaryReader& Reader)
{
	photo_id = Reader.ReadLong();
	photo_small = reinterpret_cast<COMMON::FileLocation* >(Reader.TGReadObject());
	photo_big = reinterpret_cast<COMMON::FileLocation* >(Reader.TGReadObject());
	this->_Responded = true;
}
UserProfilePhoto::~UserProfilePhoto()
{

}
}//end namespace block
