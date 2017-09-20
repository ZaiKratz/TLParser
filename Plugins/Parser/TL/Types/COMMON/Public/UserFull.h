#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"
#include "../../../Types/CONTACTS/Public/Link.h"
#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/PeerNotifySettings.h"
#include "../../../Types/Common/Public/BotInfo.h"

//begin namespace block
namespace COMMON
{
class UserFull : public TLBaseObject
{
public:
	UserFull();
	UserFull(bool blocked, bool phone_calls_available, bool phone_calls_private, COMMON::User* user, FString about, CONTACTS::Link* link, COMMON::Photo* profile_photo, COMMON::PeerNotifySettings* notify_settings, COMMON::BotInfo* bot_info, int32 common_chats_count);

	~UserFull();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool blocked;
	 bool phone_calls_available;
	 bool phone_calls_private;
	 COMMON::User* user;
	 FString about;
	 CONTACTS::Link* link;
	 COMMON::Photo* profile_photo;
	 COMMON::PeerNotifySettings* notify_settings;
	 COMMON::BotInfo* bot_info;
	 int32 common_chats_count;
};
} //end namespace block
