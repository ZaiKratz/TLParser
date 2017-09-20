#include "../Public/ChannelAdminLogEventActionParticipantJoin.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionParticipantJoin::ChannelAdminLogEventActionParticipantJoin()
{
	this->_ConstructorID = -750768104;
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
}
ChannelAdminLogEventActionParticipantJoin::~ChannelAdminLogEventActionParticipantJoin()
{

}
}//end namespace block
