#include "../Public/MessageMediaEmpty.h"


//begin namespace block
namespace COMMON
{

MessageMediaEmpty::MessageMediaEmpty()
{
	this->_ConstructorID = 1038967584;
}
void MessageMediaEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void MessageMediaEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
MessageMediaEmpty::~MessageMediaEmpty()
{

}
}//end namespace block
