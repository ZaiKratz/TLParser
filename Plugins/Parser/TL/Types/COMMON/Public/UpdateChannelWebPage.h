#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/WebPage.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChannelWebPage : public PRIVATE::Update
{
public:
	UpdateChannelWebPage();
	UpdateChannelWebPage(int32 channel_id, COMMON::WebPage* webpage, int32 pts, int32 pts_count);

	~UpdateChannelWebPage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 channel_id;
	 COMMON::WebPage* webpage;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
