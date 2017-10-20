#include "../Public/ChannelAdminLogEventActionParticipantLeave.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionParticipantLeave::ChannelAdminLogEventActionParticipantLeave()
{
	this->_ConstructorID = -124291086;
}
void ChannelAdminLogEventActionParticipantLeave::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ChannelAdminLogEventActionParticipantLeave::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
ChannelAdminLogEventActionParticipantLeave::~ChannelAdminLogEventActionParticipantLeave()
{
}
}//end namespace block
