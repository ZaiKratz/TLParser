#include "../Public/UpdateUserPhoto.h"


//begin namespace block
namespace COMMON
{

UpdateUserPhoto::UpdateUserPhoto()
{
	this->_ConstructorID = -1791935732;
}

UpdateUserPhoto::UpdateUserPhoto(int32 user_id, FDateTime date, COMMON::UserProfilePhoto*  photo, bool previous)
{
	this->_ConstructorID = -1791935732;
	this->user_id = user_id;
	this->date = date;
	this->photo = photo;
	this->previous = previous;
}
void UpdateUserPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteDate(this->date);
	this->photo->OnSend(Writer);
	Writer.WriteBool(this->previous);
}


void UpdateUserPhoto::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	date = Reader.TGReadDate();
	photo = reinterpret_cast<COMMON::UserProfilePhoto* >(Reader.TGReadObject());
	previous = Reader.ReadBool();
	this->_Responded = true;
}
UpdateUserPhoto::~UpdateUserPhoto()
{

}
}//end namespace block
