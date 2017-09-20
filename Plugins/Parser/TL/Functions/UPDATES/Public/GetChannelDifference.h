#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/ChannelMessagesFilter.h"
#include "../../../Types/Updates/Public/ChannelDifference.h"

//begin namespace block
namespace UPDATES
{
class GetChannelDifference : public TLBaseObject
{
public:
	GetChannelDifference();
	GetChannelDifference(bool force, COMMON::InputChannel* channel, COMMON::ChannelMessagesFilter* filter, int32 pts, int32 limit);

	~GetChannelDifference();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool force;
	 COMMON::InputChannel* channel;
	 COMMON::ChannelMessagesFilter* filter;
	 int32 pts;
	 int32 limit;
	UPDATES::ChannelDifference* result;
};
} //end namespace block
