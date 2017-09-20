#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionToggleSignatures : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionToggleSignatures();
	ChannelAdminLogEventActionToggleSignatures(bool new_value);

	~ChannelAdminLogEventActionToggleSignatures();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool new_value;
};
} //end namespace block
