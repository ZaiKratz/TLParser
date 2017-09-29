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

	bool Getself() const
	{
		 return this->self;
	}

	bool Getcontact() const
	{
		 return this->contact;
	}

	bool GetMutualContact() const
	{
		 return this->mutual_contact;
	}

	bool Getdeleted() const
	{
		 return this->deleted;
	}

	bool Getbot() const
	{
		 return this->bot;
	}

	bool GetBotChatHistory() const
	{
		 return this->bot_chat_history;
	}

	bool GetBotNochats() const
	{
		 return this->bot_nochats;
	}

	bool Getverified() const
	{
		 return this->verified;
	}

	bool Getrestricted() const
	{
		 return this->restricted;
	}

	bool Getmin() const
	{
		 return this->min;
	}

	bool GetBotInlineGeo() const
	{
		 return this->bot_inline_geo;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

	FString GetFirstName() const
	{
		 return this->first_name;
	}

	FString GetLastName() const
	{
		 return this->last_name;
	}

	FString Getusername() const
	{
		 return this->username;
	}

	FString Getphone() const
	{
		 return this->phone;
	}

	COMMON::UserProfilePhoto*  Getphoto() const
	{
		 return this->photo;
	}

	PRIVATE::UserStatus*  Getstatus() const
	{
		 return this->status;
	}

	int32 GetBotInfoVersion() const
	{
		 return this->bot_info_version;
	}

	FString GetRestrictionReason() const
	{
		 return this->restriction_reason;
	}

	FString GetBotInlinePlaceholder() const
	{
		 return this->bot_inline_placeholder;
	}

	FString GetLangCode() const
	{
		 return this->lang_code;
	}

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
