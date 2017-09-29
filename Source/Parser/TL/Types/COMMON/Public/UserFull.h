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

	bool Getblocked() const
	{
		 return this->blocked;
	}

	bool GetPhoneCallsAvailable() const
	{
		 return this->phone_calls_available;
	}

	bool GetPhoneCallsPrivate() const
	{
		 return this->phone_calls_private;
	}

	COMMON::User*  Getuser() const
	{
		 return this->user;
	}

	FString Getabout() const
	{
		 return this->about;
	}

	CONTACTS::Link*  Getlink() const
	{
		 return this->link;
	}

	COMMON::Photo*  GetProfilePhoto() const
	{
		 return this->profile_photo;
	}

	COMMON::PeerNotifySettings*  GetNotifySettings() const
	{
		 return this->notify_settings;
	}

	COMMON::BotInfo*  GetBotInfo() const
	{
		 return this->bot_info;
	}

	int32 GetCommonChatsCount() const
	{
		 return this->common_chats_count;
	}

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
