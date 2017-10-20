#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateDeleteChannelMessages : public TLBaseObject
{
public:
	UpdateDeleteChannelMessages();
	UpdateDeleteChannelMessages(int32 channel_id, TArray<int32> messages, int32 pts, int32 pts_count);

	~UpdateDeleteChannelMessages();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChannelId() const
	{
		 return this->channel_id;
	}

	TArray<int32>  Getmessages() const
	{
		 return this->messages;
	}

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 GetPtsCount() const
	{
		 return this->pts_count;
	}

private:
	int32 channel_id;
	 TArray<int32> messages;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
