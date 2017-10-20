#include "../Public/PeerNotifyEventsAll.h"


//begin namespace block
namespace COMMON
{

PeerNotifyEventsAll::PeerNotifyEventsAll()
{
	this->_ConstructorID = 1830677896;
}
void PeerNotifyEventsAll::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PeerNotifyEventsAll::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PeerNotifyEventsAll::~PeerNotifyEventsAll()
{
}
}//end namespace block
