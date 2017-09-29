#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Common/Public/Message.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionEditMessage : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionEditMessage();
	ChannelAdminLogEventActionEditMessage(COMMON::Message* prev_message, COMMON::Message* new_message);

	~ChannelAdminLogEventActionEditMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Message*  GetPrevMessage() const
	{
		 return this->prev_message;
	}

	COMMON::Message*  GetNewMessage() const
	{
		 return this->new_message;
	}

private:
	COMMON::Message* prev_message;
	 COMMON::Message* new_message;
};
} //end namespace block
