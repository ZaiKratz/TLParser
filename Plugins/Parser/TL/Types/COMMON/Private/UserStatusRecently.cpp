#include "../Public/UserStatusRecently.h"


//begin namespace block
namespace COMMON
{

UserStatusRecently::UserStatusRecently()
{
	this->_ConstructorID = -247304222;
}
void UserStatusRecently::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UserStatusRecently::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
UserStatusRecently::~UserStatusRecently()
{

}
}//end namespace block
