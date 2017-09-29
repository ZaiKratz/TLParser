#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChannelMessageViews : public PRIVATE::Update
{
public:
	UpdateChannelMessageViews();
	UpdateChannelMessageViews(int32 channel_id, int32 id, int32 views);

	~UpdateChannelMessageViews();
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

	int32 Getviews() const
	{
		 return this->views;
	}

private:
	int32 channel_id;
	 int32 id;
	 int32 views;
};
} //end namespace block
