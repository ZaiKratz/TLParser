#include "../Public/UserStatusOnline.h"


//begin namespace block
namespace COMMON
{

UserStatusOnline::UserStatusOnline()
{
	this->_ConstructorID = 1228519917;
}

UserStatusOnline::UserStatusOnline(FDateTime expires)
{
	this->_ConstructorID = 1228519917;
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
}
UserStatusOnline::~UserStatusOnline()
{

}
}//end namespace block
