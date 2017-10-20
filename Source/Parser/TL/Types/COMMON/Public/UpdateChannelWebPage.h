#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/WebPage.h"

//begin namespace block
namespace COMMON
{
class UpdateChannelWebPage : public TLBaseObject
{
public:
	UpdateChannelWebPage();
	UpdateChannelWebPage(int32 channel_id, COMMON::WebPage* webpage, int32 pts, int32 pts_count);

	~UpdateChannelWebPage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChannelId() const
	{
		 return this->channel_id;
	}

	COMMON::WebPage*  Getwebpage() const
	{
		 return this->webpage;
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
	 COMMON::WebPage* webpage;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
