#include "../Public/UserStatusEmpty.h"


//begin namespace block
namespace COMMON
{

UserStatusEmpty::UserStatusEmpty()
{
	this->_ConstructorID = 64;
}
void UserStatusEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UserStatusEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
UserStatusEmpty::~UserStatusEmpty()
{

}
}//end namespace block
