#include "../Public/NotifyAll.h"


//begin namespace block
namespace COMMON
{

NotifyAll::NotifyAll()
{
	this->_ConstructorID = 1618792564;
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
}
NotifyAll::~NotifyAll()
{

}
}//end namespace block
