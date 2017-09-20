#include "../Public/ChannelAdminLogEventActionParticipantToggleAdmin.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionParticipantToggleAdmin::ChannelAdminLogEventActionParticipantToggleAdmin()
{
	this->_ConstructorID = 275212245;
}

ChannelAdminLogEventActionParticipantToggleAdmin::ChannelAdminLogEventActionParticipantToggleAdmin(COMMON::ChannelParticipant* prev_participant, COMMON::ChannelParticipant* new_participant)
{
	this->_ConstructorID = 275212245;
	this->prev_participant = prev_participant;
	this->new_participant = new_participant;
}
void ChannelAdminLogEventActionParticipantToggleAdmin::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->prev_participant->OnSend(Writer);
	this->new_participant->OnSend(Writer);
}


void ChannelAdminLogEventActionParticipantToggleAdmin::OnResponce(BinaryReader& Reader)
{
	prev_participant = reinterpret_cast<COMMON::ChannelParticipant*>(Reader.TGReadObject());
	new_participant = reinterpret_cast<COMMON::ChannelParticipant*>(Reader.TGReadObject());
}
ChannelAdminLogEventActionParticipantToggleAdmin::~ChannelAdminLogEventActionParticipantToggleAdmin()
{

}
}//end namespace block