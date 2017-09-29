#include "../Public/UserStatusOnline.h"


//begin namespace block
namespace COMMON
{

UserStatusOnline::UserStatusOnline()
{
	this->_ConstructorID = -306628279;
}

UserStatusOnline::UserStatusOnline(FDateTime expires)
{
	this->_ConstructorID = -306628279;
	this->expires = expires;
}
void UserStatusOnline::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteDate(this->expires);
}


void UserStatusOnline::OnResponce(BinaryReader& Reader)
{
	expires = Reader.TGReadDate();
	this->_Responded = true;
}
UserStatusOnline::~UserStatusOnline()
{

}
}//end namespace block
