#include "../Public/InputPeerNotifyEventsEmpty.h"


//begin namespace block
namespace COMMON
{

InputPeerNotifyEventsEmpty::InputPeerNotifyEventsEmpty()
{
	this->_ConstructorID = -265263912;
}
void InputPeerNotifyEventsEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPeerNotifyEventsEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputPeerNotifyEventsEmpty::~InputPeerNotifyEventsEmpty()
{
}
}//end namespace block
