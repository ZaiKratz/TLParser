#include "../Public/UserStatusLastWeek.h"


//begin namespace block
namespace COMMON
{

UserStatusLastWeek::UserStatusLastWeek()
{
	this->_ConstructorID = 129960444;
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
	this->_Responded = true;
}
UserStatusLastWeek::~UserStatusLastWeek()
{

}
}//end namespace block
