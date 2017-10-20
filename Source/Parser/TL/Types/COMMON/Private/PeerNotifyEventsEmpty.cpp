#include "../Public/PeerNotifyEventsEmpty.h"


//begin namespace block
namespace COMMON
{

PeerNotifyEventsEmpty::PeerNotifyEventsEmpty()
{
	this->_ConstructorID = -1378534221;
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
	this->_Responded = true;
}
PeerNotifyEventsEmpty::~PeerNotifyEventsEmpty()
{
}
}//end namespace block
