#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/ChannelAdminLogEventsFilter.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Channels/Public/AdminLogResults.h"

//begin namespace block
namespace CHANNELS
{
class GetAdminLog : public TLBaseObject
{
public:
	GetAdminLog();
	GetAdminLog(COMMON::InputChannel* channel, FString q, COMMON::ChannelAdminLogEventsFilter* events_filter, TArray<COMMON::InputUser*> admins, unsigned long long max_id, unsigned long long min_id, int32 limit);

	~GetAdminLog();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	FString Getq() const
	{
		 return this->q;
	}

	COMMON::ChannelAdminLogEventsFilter*  GetEventsFilter() const
	{
		 return this->events_filter;
	}

	TArray<COMMON::InputUser*>  Getadmins() const
	{
		 return this->admins;
	}

	unsigned long long GetMaxId() const
	{
		 return this->max_id;
	}

	unsigned long long GetMinId() const
	{
		 return this->min_id;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	CHANNELS::AdminLogResults* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 FString q;
	 COMMON::ChannelAdminLogEventsFilter* events_filter;
	 TArray<COMMON::InputUser*> admins;
	 unsigned long long max_id;
	 unsigned long long min_id;
	 int32 limit;
	CHANNELS::AdminLogResults* result;
};
} //end namespace block
