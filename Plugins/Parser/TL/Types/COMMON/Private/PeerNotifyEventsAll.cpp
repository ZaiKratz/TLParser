#include "../Public/PeerNotifyEventsAll.h"


//begin namespace block
namespace COMMON
{

PeerNotifyEventsAll::PeerNotifyEventsAll()
{
	this->_ConstructorID = -1997726355;
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
}
PeerNotifyEventsAll::~PeerNotifyEventsAll()
{

}
}//end namespace block
