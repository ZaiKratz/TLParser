#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionParticipantJoin : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionParticipantJoin();
	~ChannelAdminLogEventActionParticipantJoin();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
