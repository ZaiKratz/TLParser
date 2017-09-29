#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Channels/Public/ChannelParticipant.h"

//begin namespace block
namespace CHANNELS
{
class GetParticipant : public TLBaseObject
{
public:
	GetParticipant();
	GetParticipant(COMMON::InputChannel* channel, COMMON::InputUser* user_id);

	~GetParticipant();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	COMMON::InputUser*  GetUserId() const
	{
		 return this->user_id;
	}

	CHANNELS::ChannelParticipant* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 COMMON::InputUser* user_id;
	CHANNELS::ChannelParticipant* result;
};
} //end namespace block
