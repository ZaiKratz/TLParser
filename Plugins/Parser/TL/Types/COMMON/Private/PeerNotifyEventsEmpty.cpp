#include "../Public/PeerNotifyEventsEmpty.h"


//begin namespace block
namespace COMMON
{

PeerNotifyEventsEmpty::PeerNotifyEventsEmpty()
{
	this->_ConstructorID = -1287858771;
}
void PeerNotifyEventsEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PeerNotifyEventsEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
PeerNotifyEventsEmpty::~PeerNotifyEventsEmpty()
{

}
}//end namespace block
