#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/PeerNotifySettings.h"
#include "../../../Types/Common/Public/BotInfo.h"
#include "../../../Types/Common/Public/StickerSet.h"
#include "../../../Types/Common/Public/ChatFull.h"

//begin namespace block
namespace COMMON
{
class ChannelFull : public TLBaseObject
{
public:
	ChannelFull();
	ChannelFull(bool can_view_participants, bool can_set_username, bool can_set_stickers, int32 id, FString about, int32 participants_count, int32 admins_count, int32 kicked_count, int32 banned_count, int32 read_inbox_max_id, int32 read_outbox_max_id, int32 unread_count, COMMON::Photo* chat_photo, COMMON::PeerNotifySettings* notify_settings, TLBaseObject* exported_invite, TArray<COMMON::BotInfo*> bot_info, int32 migrated_from_chat_id, int32 migrated_from_max_id, int32 pinned_msg_id, COMMON::StickerSet* stickerset);

	~ChannelFull();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetCanViewParticipants() const
	{
		 return this->can_view_participants;
	}

	bool GetCanSetUsername() const
	{
		 return this->can_set_username;
	}

	bool GetCanSetStickers() const
	{
		 return this->can_set_stickers;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	FString Getabout() const
	{
		 return this->about;
	}

	int32 GetParticipantsCount() const
	{
		 return this->participants_count;
	}

	int32 GetAdminsCount() const
	{
		 return this->admins_count;
	}

	int32 GetKickedCount() const
	{
		 return this->kicked_count;
	}

	int32 GetBannedCount() const
	{
		 return this->banned_count;
	}

	int32 GetReadInboxMaxId() const
	{
		 return this->read_inbox_max_id;
	}

	int32 GetReadOutboxMaxId() const
	{
		 return this->read_outbox_max_id;
	}

	int32 GetUnreadCount() const
	{
		 return this->unread_count;
	}

	COMMON::Photo*  GetChatPhoto() const
	{
		 return this->chat_photo;
	}

	COMMON::PeerNotifySettings*  GetNotifySettings() const
	{
		 return this->notify_settings;
	}

	TLBaseObject*  GetExportedInvite() const
	{
		 return this->exported_invite;
	}

	TArray<COMMON::BotInfo*>  GetBotInfo() const
	{
		 return this->bot_info;
	}

	int32 GetMigratedFromChatId() const
	{
		 return this->migrated_from_chat_id;
	}

	int32 GetMigratedFromMaxId() const
	{
		 return this->migrated_from_max_id;
	}

	int32 GetPinnedMsgId() const
	{
		 return this->pinned_msg_id;
	}

	COMMON::StickerSet*  Getstickerset() const
	{
		 return this->stickerset;
	}

private:
	bool can_view_participants;
	 bool can_set_username;
	 bool can_set_stickers;
	 int32 id;
	 FString about;
	 int32 participants_count;
	 int32 admins_count;
	 int32 kicked_count;
	 int32 banned_count;
	 int32 read_inbox_max_id;
	 int32 read_outbox_max_id;
	 int32 unread_count;
	 COMMON::Photo* chat_photo;
	 COMMON::PeerNotifySettings* notify_settings;
	 TLBaseObject* exported_invite;
	 TArray<COMMON::BotInfo*> bot_info;
	 int32 migrated_from_chat_id;
	 int32 migrated_from_max_id;
	 int32 pinned_msg_id;
	 COMMON::StickerSet* stickerset;
};
} //end namespace block
