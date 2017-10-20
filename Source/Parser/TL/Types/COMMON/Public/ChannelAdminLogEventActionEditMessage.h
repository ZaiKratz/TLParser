#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Message.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionEditMessage : public TLBaseObject
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
