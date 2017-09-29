#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatPhoto.h"
#include "../../../Types/Common/Public/ChannelAdminRights.h"
#include "../../../Types/Common/Public/ChannelBannedRights.h"
#include "../../../Types/Common/Public/Chat.h"

//begin namespace block
namespace COMMON
{
class Channel : public TLBaseObject
{
public:
	Channel();
	Channel(bool creator, bool left, bool editor, bool broadcast, bool verified, bool megagroup, bool restricted, bool democracy, bool signatures, bool min, int32 id, unsigned long long access_hash, FString title, FString username, COMMON::ChatPhoto* photo, FDateTime date, int32 version, FString restriction_reason, COMMON::ChannelAdminRights* admin_rights, COMMON::ChannelBannedRights* banned_rights);

	~Channel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getcreator() const
	{
		 return this->creator;
	}

	bool Getleft() const
	{
		 return this->left;
	}

	bool Geteditor() const
	{
		 return this->editor;
	}

	bool Getbroadcast() const
	{
		 return this->broadcast;
	}

	bool Getverified() const
	{
		 return this->verified;
	}

	bool Getmegagroup() const
	{
		 return this->megagroup;
	}

	bool Getrestricted() const
	{
		 return this->restricted;
	}

	bool Getdemocracy() const
	{
		 return this->democracy;
	}

	bool Getsignatures() const
	{
		 return this->signatures;
	}

	bool Getmin() const
	{
		 return this->min;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getusername() const
	{
		 return this->username;
	}

	COMMON::ChatPhoto*  Getphoto() const
	{
		 return this->photo;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 Getversion() const
	{
		 return this->version;
	}

	FString GetRestrictionReason() const
	{
		 return this->restriction_reason;
	}

	COMMON::ChannelAdminRights*  GetAdminRights() const
	{
		 return this->admin_rights;
	}

	COMMON::ChannelBannedRights*  GetBannedRights() const
	{
		 return this->banned_rights;
	}

private:
	bool creator;
	 bool left;
	 bool editor;
	 bool broadcast;
	 bool verified;
	 bool megagroup;
	 bool restricted;
	 bool democracy;
	 bool signatures;
	 bool min;
	 int32 id;
	 unsigned long long access_hash;
	 FString title;
	 FString username;
	 COMMON::ChatPhoto* photo;
	 FDateTime date;
	 int32 version;
	 FString restriction_reason;
	 COMMON::ChannelAdminRights* admin_rights;
	 COMMON::ChannelBannedRights* banned_rights;
};
} //end namespace block
