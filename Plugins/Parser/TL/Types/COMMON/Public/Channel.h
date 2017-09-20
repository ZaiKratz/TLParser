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
