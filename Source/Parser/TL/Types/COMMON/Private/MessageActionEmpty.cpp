#include "../Public/MessageActionEmpty.h"


//begin namespace block
namespace COMMON
{

MessageActionEmpty::MessageActionEmpty()
{
	this->_ConstructorID = -1230047312;
}
void MessageActionEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void MessageActionEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
MessageActionEmpty::~MessageActionEmpty()
{

}
}//end namespace block
