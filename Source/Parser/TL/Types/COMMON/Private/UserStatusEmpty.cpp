#include "../Public/UserStatusEmpty.h"


//begin namespace block
namespace COMMON
{

UserStatusEmpty::UserStatusEmpty()
{
	this->_ConstructorID = 164646985;
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
	this->_Responded = true;
}
UserStatusEmpty::~UserStatusEmpty()
{
}
}//end namespace block
