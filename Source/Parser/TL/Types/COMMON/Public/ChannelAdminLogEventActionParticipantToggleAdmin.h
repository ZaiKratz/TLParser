#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Common/Public/ChannelParticipant.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionParticipantToggleAdmin : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionParticipantToggleAdmin();
	ChannelAdminLogEventActionParticipantToggleAdmin(COMMON::ChannelParticipant* prev_participant, COMMON::ChannelParticipant* new_participant);

	~ChannelAdminLogEventActionParticipantToggleAdmin();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::ChannelParticipant*  GetPrevParticipant() const
	{
		 return this->prev_participant;
	}

	COMMON::ChannelParticipant*  GetNewParticipant() const
	{
		 return this->new_participant;
	}

private:
	COMMON::ChannelParticipant* prev_participant;
	 COMMON::ChannelParticipant* new_participant;
};
} //end namespace block