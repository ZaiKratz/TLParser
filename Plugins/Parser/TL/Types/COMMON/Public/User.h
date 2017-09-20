#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/UserProfilePhoto.h"
#include "../../../Types/Private/UserStatus.h"

//begin namespace block
namespace COMMON
{
class User : public TLBaseObject
{
public:
	User();
	User(bool self, bool contact, bool mutual_contact, bool deleted, bool bot, bool bot_chat_history, bool bot_nochats, bool verified, bool restricted, bool min, bool bot_inline_geo, int32 id, unsigned long long access_hash, FString first_name, FString last_name, FString username, FString phone, COMMON::UserProfilePhoto* photo, PRIVATE::UserStatus* status, int32 bot_info_version, FString restriction_reason, FString bot_inline_placeholder, FString lang_code);

	~User();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool self;
	 bool contact;
	 bool mutual_contact;
	 bool deleted;
	 bool bot;
	 bool bot_chat_history;
	 bool bot_nochats;
	 bool verified;
	 bool restricted;
	 bool min;
	 bool bot_inline_geo;
	 int32 id;
	 unsigned long long access_hash;
	 FString first_name;
	 FString last_name;
	 FString username;
	 FString phone;
	 COMMON::UserProfilePhoto* photo;
	 PRIVATE::UserStatus* status;
	 int32 bot_info_version;
	 FString restriction_reason;
	 FString bot_inline_placeholder;
	 FString lang_code;
};
} //end namespace block
