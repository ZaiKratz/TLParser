#include "../Public/MessageMediaUnsupported.h"


//begin namespace block
namespace COMMON
{

MessageMediaUnsupported::MessageMediaUnsupported()
{
	this->_ConstructorID = -1618676578;
}
void MessageMediaUnsupported::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void MessageMediaUnsupported::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
MessageMediaUnsupported::~MessageMediaUnsupported()
{
}
}//end namespace block
