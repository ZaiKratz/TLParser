#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/PeerNotifySettings.h"
#include "../../../Types/Private/ExportedChatInvite.h"
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
	ChannelFull(bool can_view_participants, bool can_set_username, bool can_set_stickers, int32 id, FString about, int32 participants_count, int32 admins_count, int32 kicked_count, int32 banned_count, int32 read_inbox_max_id, int32 read_outbox_max_id, int32 unread_count, COMMON::Photo* chat_photo, COMMON::PeerNotifySettings* notify_settings, PRIVATE::ExportedChatInvite* exported_invite, TArray<COMMON::BotInfo*> bot_info, int32 migrated_from_chat_id, int32 migrated_from_max_id, int32 pinned_msg_id, COMMON::StickerSet* stickerset);

	~ChannelFull();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
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
	 PRIVATE::ExportedChatInvite* exported_invite;
	 TArray<COMMON::BotInfo*> bot_info;
	 int32 migrated_from_chat_id;
	 int32 migrated_from_max_id;
	 int32 pinned_msg_id;
	 COMMON::StickerSet* stickerset;
};
} //end namespace block
