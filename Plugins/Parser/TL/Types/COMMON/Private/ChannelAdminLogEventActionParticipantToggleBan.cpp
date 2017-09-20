#include "../Public/ChannelAdminLogEventActionParticipantToggleBan.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionParticipantToggleBan::ChannelAdminLogEventActionParticipantToggleBan()
{
	this->_ConstructorID = 2117982438;
}

ChannelAdminLogEventActionParticipantToggleBan::ChannelAdminLogEventActionParticipantToggleBan(COMMON::ChannelParticipant* prev_participant, COMMON::ChannelParticipant* new_participant)
{
	this->_ConstructorID = 2117982438;
	this->prev_participant = prev_participant;
	this->new_participant = new_participant;
}
void ChannelAdminLogEventActionParticipantToggleBan::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->prev_participant->OnSend(Writer);
	this->new_participant->OnSend(Writer);
}


void ChannelAdminLogEventActionParticipantToggleBan::OnResponce(BinaryReader& Reader)
{
	prev_participant = reinterpret_cast<COMMON::ChannelParticipant*>(Reader.TGReadObject());
	new_participant = reinterpret_cast<COMMON::ChannelParticipant*>(Reader.TGReadObject());
}
ChannelAdminLogEventActionParticipantToggleBan::~ChannelAdminLogEventActionParticipantToggleBan()
{

}
}//end namespace block
