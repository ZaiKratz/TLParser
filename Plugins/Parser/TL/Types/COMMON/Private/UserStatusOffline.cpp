#include "../Public/UserStatusOffline.h"


//begin namespace block
namespace COMMON
{

UserStatusOffline::UserStatusOffline()
{
	this->_ConstructorID = 4157580;
}

UserStatusOffline::UserStatusOffline(FDateTime was_online)
{
	this->_ConstructorID = 4157580;
	this->was_online = was_online;
}
void UserStatusOffline::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteDate(this->was_online);
}


void UserStatusOffline::OnResponce(BinaryReader& Reader)
{
	was_online = Reader.TGReadDate();
}
UserStatusOffline::~UserStatusOffline()
{

}
}//end namespace block
