#include "../Public/MessageMediaUnsupported.h"


//begin namespace block
namespace COMMON
{

MessageMediaUnsupported::MessageMediaUnsupported()
{
	this->_ConstructorID = -1628142433;
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
}
MessageMediaUnsupported::~MessageMediaUnsupported()
{

}
}//end namespace block
