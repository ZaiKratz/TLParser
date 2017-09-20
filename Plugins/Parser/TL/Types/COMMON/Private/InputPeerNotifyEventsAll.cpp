#include "../Public/InputPeerNotifyEventsAll.h"


//begin namespace block
namespace COMMON
{

InputPeerNotifyEventsAll::InputPeerNotifyEventsAll()
{
	this->_ConstructorID = 1949068008;
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
}
InputPeerNotifyEventsAll::~InputPeerNotifyEventsAll()
{

}
}//end namespace block
