#include "../Public/ChannelParticipantsRecent.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsRecent::ChannelParticipantsRecent()
{
	this->_ConstructorID = 2033991646;
}
void ChannelParticipantsRecent::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ChannelParticipantsRecent::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
ChannelParticipantsRecent::~ChannelParticipantsRecent()
{

}
}//end namespace block
