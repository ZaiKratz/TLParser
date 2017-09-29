#include "../Public/NotifyChats.h"


//begin namespace block
namespace COMMON
{

NotifyChats::NotifyChats()
{
	this->_ConstructorID = -1073230141;
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
	this->_Responded = true;
}
NotifyChats::~NotifyChats()
{

}
}//end namespace block
