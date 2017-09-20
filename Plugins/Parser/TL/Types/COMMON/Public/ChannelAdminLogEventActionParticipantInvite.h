#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Common/Public/ChannelParticipant.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionParticipantInvite : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionParticipantInvite();
	ChannelAdminLogEventActionParticipantInvite(COMMON::ChannelParticipant* participant);

	~ChannelAdminLogEventActionParticipantInvite();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::ChannelParticipant* participant;
};
} //end namespace block
