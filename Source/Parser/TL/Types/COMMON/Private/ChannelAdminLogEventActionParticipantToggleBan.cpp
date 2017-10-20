#include "../Public/ChannelAdminLogEventActionParticipantToggleBan.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionParticipantToggleBan::ChannelAdminLogEventActionParticipantToggleBan()
{
	this->_ConstructorID = -422036098;
}

ChannelAdminLogEventActionParticipantToggleBan::ChannelAdminLogEventActionParticipantToggleBan(COMMON::ChannelParticipant*  prev_participant, COMMON::ChannelParticipant*  new_participant)
{
	this->_ConstructorID = -422036098;
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
	prev_participant = reinterpret_cast<COMMON::ChannelParticipant* >(Reader.TGReadObject());
	new_participant = reinterpret_cast<COMMON::ChannelParticipant* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChannelAdminLogEventActionParticipantToggleBan::~ChannelAdminLogEventActionParticipantToggleBan()
{
	if(this->prev_participant)
	{
		delete this->prev_participant;
	}
	if(this->new_participant)
	{
		delete this->new_participant;
	}
}
}//end namespace block
