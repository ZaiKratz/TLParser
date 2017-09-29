#include "../Public/InputPeerNotifyEventsAll.h"


//begin namespace block
namespace COMMON
{

InputPeerNotifyEventsAll::InputPeerNotifyEventsAll()
{
	this->_ConstructorID = -395694988;
}
void InputPeerNotifyEventsAll::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPeerNotifyEventsAll::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputPeerNotifyEventsAll::~InputPeerNotifyEventsAll()
{

}
}//end namespace block
