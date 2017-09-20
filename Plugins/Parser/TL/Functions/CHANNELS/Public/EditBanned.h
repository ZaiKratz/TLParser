#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/ChannelBannedRights.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class EditBanned : public TLBaseObject
{
public:
	EditBanned();
	EditBanned(COMMON::InputChannel* channel, COMMON::InputUser* user_id, COMMON::ChannelBannedRights* banned_rights);

	~EditBanned();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	 COMMON::InputUser* user_id;
	 COMMON::ChannelBannedRights* banned_rights;
	COMMON::Updates* result;
};
} //end namespace block