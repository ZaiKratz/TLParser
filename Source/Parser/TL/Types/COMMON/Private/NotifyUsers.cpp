#include "../Public/NotifyUsers.h"


//begin namespace block
namespace COMMON
{

NotifyUsers::NotifyUsers()
{
	this->_ConstructorID = -1261946036;
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
	this->_Responded = true;
}
NotifyUsers::~NotifyUsers()
{
}
}//end namespace block
