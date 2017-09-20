#include "../Public/UserStatusLastMonth.h"


//begin namespace block
namespace COMMON
{

UserStatusLastMonth::UserStatusLastMonth()
{
	this->_ConstructorID = 1120398199;
}
void UserStatusLastMonth::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UserStatusLastMonth::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
UserStatusLastMonth::~UserStatusLastMonth()
{

}
}//end namespace block
