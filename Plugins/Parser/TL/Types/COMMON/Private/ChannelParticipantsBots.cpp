#include "../Public/ChannelParticipantsBots.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantsBots::ChannelParticipantsBots()
{
	this->_ConstructorID = 1535562160;
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
}
ChannelParticipantsBots::~ChannelParticipantsBots()
{

}
}//end namespace block
