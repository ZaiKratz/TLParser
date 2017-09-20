#include "../Public/MessageActionEmpty.h"


//begin namespace block
namespace COMMON
{

MessageActionEmpty::MessageActionEmpty()
{
	this->_ConstructorID = -1325945162;
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
}
MessageActionEmpty::~MessageActionEmpty()
{

}
}//end namespace block
