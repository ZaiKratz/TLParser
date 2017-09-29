#include "../Public/UserStatusRecently.h"


//begin namespace block
namespace COMMON
{

UserStatusRecently::UserStatusRecently()
{
	this->_ConstructorID = -496024847;
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
	this->_Responded = true;
}
UserStatusRecently::~UserStatusRecently()
{

}
}//end namespace block
