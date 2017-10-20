#include "../Public/ChannelParticipantsBots.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsBots::ChannelParticipantsBots()
{
	this->_ConstructorID = -1328445861;
}
void ChannelParticipantsBots::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ChannelParticipantsBots::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
ChannelParticipantsBots::~ChannelParticipantsBots()
{
}
}//end namespace block
