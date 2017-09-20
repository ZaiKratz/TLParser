#include "../Public/ChannelMessagesFilterEmpty.h"


//begin namespace block
namespace COMMON
{

ChannelMessagesFilterEmpty::ChannelMessagesFilterEmpty()
{
	this->_ConstructorID = -416361324;
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
}
ChannelMessagesFilterEmpty::~ChannelMessagesFilterEmpty()
{

}
}//end namespace block
