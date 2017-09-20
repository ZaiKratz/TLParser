#include "../Public/InputPeerNotifyEventsEmpty.h"


//begin namespace block
namespace COMMON
{

InputPeerNotifyEventsEmpty::InputPeerNotifyEventsEmpty()
{
	this->_ConstructorID = -664522512;
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
}
InputPeerNotifyEventsEmpty::~InputPeerNotifyEventsEmpty()
{

}
}//end namespace block
