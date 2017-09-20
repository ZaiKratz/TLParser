#include "../Public/MessageMediaEmpty.h"


//begin namespace block
namespace COMMON
{

MessageMediaEmpty::MessageMediaEmpty()
{
	this->_ConstructorID = 543419709;
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
}
MessageMediaEmpty::~MessageMediaEmpty()
{

}
}//end namespace block
