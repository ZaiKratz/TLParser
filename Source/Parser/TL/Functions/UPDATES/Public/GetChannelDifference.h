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

	bool Getforce() const
	{
		 return this->force;
	}

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	COMMON::ChannelMessagesFilter*  Getfilter() const
	{
		 return this->filter;
	}

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	UPDATES::ChannelDifference* GetResult() const
	{
		 return this->result;
	}

private:
	bool force;
	 COMMON::InputChannel* channel;
	 COMMON::ChannelMessagesFilter* filter;
	 int32 pts;
	 int32 limit;
	UPDATES::ChannelDifference* result;
};
} //end namespace block
