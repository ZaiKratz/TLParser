#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChannelPinnedMessage : public PRIVATE::Update
{
public:
	UpdateChannelPinnedMessage();
	UpdateChannelPinnedMessage(int32 channel_id, int32 id);

	~UpdateChannelPinnedMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChannelId() const
	{
		 return this->channel_id;
	}

	int32 Getid() const
	{
		 return this->id;
	}

private:
	int32 channel_id;
	 int32 id;
};
} //end namespace block
