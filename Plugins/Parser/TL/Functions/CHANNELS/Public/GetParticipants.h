#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Private/ChannelParticipantsFilter.h"
#include "../../../Types/Channels/Public/ChannelParticipants.h"

//begin namespace block
namespace CHANNELS
{
class GetParticipants : public TLBaseObject
{
public:
	GetParticipants();
	GetParticipants(COMMON::InputChannel* channel, PRIVATE::ChannelParticipantsFilter* filter, int32 offset, int32 limit);

	~GetParticipants();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	 PRIVATE::ChannelParticipantsFilter* filter;
	 int32 offset;
	 int32 limit;
	CHANNELS::ChannelParticipants* result;
};
} //end namespace block
