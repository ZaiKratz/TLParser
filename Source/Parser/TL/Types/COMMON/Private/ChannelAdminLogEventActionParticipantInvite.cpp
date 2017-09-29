#include "../Public/ChannelAdminLogEventActionParticipantInvite.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionParticipantInvite::ChannelAdminLogEventActionParticipantInvite()
{
	this->_ConstructorID = -484690728;
}

ChannelAdminLogEventActionParticipantInvite::ChannelAdminLogEventActionParticipantInvite(COMMON::ChannelParticipant*  participant)
{
	this->_ConstructorID = -484690728;
	this->participant = participant;
}
void ChannelAdminLogEventActionParticipantInvite::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->participant->OnSend(Writer);
}


void ChannelAdminLogEventActionParticipantInvite::OnResponce(BinaryReader& Reader)
{
	participant = reinterpret_cast<COMMON::ChannelParticipant* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChannelAdminLogEventActionParticipantInvite::~ChannelAdminLogEventActionParticipantInvite()
{

}
}//end namespace block
