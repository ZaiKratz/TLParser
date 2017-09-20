#include "../Public/ChannelAdminLogEventActionParticipantLeave.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionParticipantLeave::ChannelAdminLogEventActionParticipantLeave()
{
	this->_ConstructorID = -227043336;
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
}
ChannelAdminLogEventActionParticipantLeave::~ChannelAdminLogEventActionParticipantLeave()
{

}
}//end namespace block
