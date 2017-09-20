#include "../Public/NotifyUsers.h"


//begin namespace block
namespace COMMON
{

NotifyUsers::NotifyUsers()
{
	this->_ConstructorID = 1278986420;
}
void NotifyUsers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void NotifyUsers::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
NotifyUsers::~NotifyUsers()
{

}
}//end namespace block
