#include "../Public/MessageActionPinMessage.h"


//begin namespace block
namespace COMMON
{

MessageActionPinMessage::MessageActionPinMessage()
{
	this->_ConstructorID = -315048556;
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
}
MessageActionPinMessage::~MessageActionPinMessage()
{

}
}//end namespace block
