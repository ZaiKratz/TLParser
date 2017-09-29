#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Common/Public/Message.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionDeleteMessage : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionDeleteMessage();
	ChannelAdminLogEventActionDeleteMessage(COMMON::Message* message);

	~ChannelAdminLogEventActionDeleteMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Message*  Getmessage() const
	{
		 return this->message;
	}

private:
	COMMON::Message* message;
};
} //end namespace block
