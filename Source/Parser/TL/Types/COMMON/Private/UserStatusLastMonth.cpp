#include "../Public/UserStatusLastMonth.h"


//begin namespace block
namespace COMMON
{

UserStatusLastMonth::UserStatusLastMonth()
{
	this->_ConstructorID = 2011940674;
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
	this->_Responded = true;
}
UserStatusLastMonth::~UserStatusLastMonth()
{
}
}//end namespace block
