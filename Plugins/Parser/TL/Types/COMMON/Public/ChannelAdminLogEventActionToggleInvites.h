#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionToggleInvites : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionToggleInvites();
	ChannelAdminLogEventActionToggleInvites(bool new_value);

	~ChannelAdminLogEventActionToggleInvites();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool new_value;
};
} //end namespace block
