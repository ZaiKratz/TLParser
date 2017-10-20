#include "../Public/NotifyAll.h"


//begin namespace block
namespace COMMON
{

NotifyAll::NotifyAll()
{
	this->_ConstructorID = 1959820384;
}
void NotifyAll::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void NotifyAll::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
NotifyAll::~NotifyAll()
{
}
}//end namespace block
