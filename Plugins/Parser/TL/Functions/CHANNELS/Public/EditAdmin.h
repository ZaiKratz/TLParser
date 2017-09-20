#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/ChannelAdminRights.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class EditAdmin : public TLBaseObject
{
public:
	EditAdmin();
	EditAdmin(COMMON::InputChannel* channel, COMMON::InputUser* user_id, COMMON::ChannelAdminRights* admin_rights);

	~EditAdmin();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	 COMMON::InputUser* user_id;
	 COMMON::ChannelAdminRights* admin_rights;
	COMMON::Updates* result;
};
} //end namespace block