#pragma once
#include "Engine.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

#include "../../../Types/Common/Public/ChatPhoto.h"
#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionChangePhoto : public PRIVATE::ChannelAdminLogEventAction
{
public:
	ChannelAdminLogEventActionChangePhoto();
	ChannelAdminLogEventActionChangePhoto(COMMON::ChatPhoto* prev_photo, COMMON::ChatPhoto* new_photo);

	~ChannelAdminLogEventActionChangePhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::ChatPhoto* prev_photo;
	 COMMON::ChatPhoto* new_photo;
};
} //end namespace block
