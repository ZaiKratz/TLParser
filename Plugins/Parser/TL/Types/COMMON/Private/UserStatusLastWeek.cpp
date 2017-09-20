#include "../Public/UserStatusLastWeek.h"


//begin namespace block
namespace COMMON
{

UserStatusLastWeek::UserStatusLastWeek()
{
	this->_ConstructorID = 64;
}
void UserStatusLastWeek::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UserStatusLastWeek::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
UserStatusLastWeek::~UserStatusLastWeek()
{

}
}//end namespace block
