#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionParticipantLeave : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionParticipantLeave();
	~ChannelAdminLogEventActionParticipantLeave();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
