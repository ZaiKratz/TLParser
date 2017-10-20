#include "../Public/MessageActionPinMessage.h"


//begin namespace block
namespace COMMON
{

MessageActionPinMessage::MessageActionPinMessage()
{
	this->_ConstructorID = -1799538451;
}
void MessageActionPinMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void MessageActionPinMessage::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
MessageActionPinMessage::~MessageActionPinMessage()
{
}
}//end namespace block
