#include "../Public/ChannelParticipantsRecent.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsRecent::ChannelParticipantsRecent()
{
	this->_ConstructorID = -566281095;
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
	this->_Responded = true;
}
ChannelParticipantsRecent::~ChannelParticipantsRecent()
{

}
}//end namespace block
