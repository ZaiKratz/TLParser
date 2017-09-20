#include "../Public/NotifyChats.h"


//begin namespace block
namespace COMMON
{

NotifyChats::NotifyChats()
{
	this->_ConstructorID = -1009907776;
}
void NotifyChats::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void NotifyChats::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
NotifyChats::~NotifyChats()
{

}
}//end namespace block
