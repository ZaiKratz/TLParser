#include "../Public/ChannelMessagesFilterEmpty.h"


//begin namespace block
namespace COMMON
{

ChannelMessagesFilterEmpty::ChannelMessagesFilterEmpty()
{
	this->_ConstructorID = -1798033689;
}
void ChannelMessagesFilterEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ChannelMessagesFilterEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
ChannelMessagesFilterEmpty::~ChannelMessagesFilterEmpty()
{
}
}//end namespace block
