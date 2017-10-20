#include "../Public/ChannelAdminLogEventActionParticipantJoin.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionParticipantJoin::ChannelAdminLogEventActionParticipantJoin()
{
	this->_ConstructorID = 405815507;
}
void ChannelAdminLogEventActionParticipantJoin::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ChannelAdminLogEventActionParticipantJoin::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
ChannelAdminLogEventActionParticipantJoin::~ChannelAdminLogEventActionParticipantJoin()
{
}
}//end namespace block
