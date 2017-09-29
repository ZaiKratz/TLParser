#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChannelTooLong : public PRIVATE::Update
{
public:
	UpdateChannelTooLong();
	UpdateChannelTooLong(int32 channel_id, int32 pts);

	~UpdateChannelTooLong();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChannelId() const
	{
		 return this->channel_id;
	}

	int32 Getpts() const
	{
		 return this->pts;
	}

private:
	int32 channel_id;
	 int32 pts;
};
} //end namespace block