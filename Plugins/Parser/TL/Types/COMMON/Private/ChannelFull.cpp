#include "../Public/ChannelFull.h"


//begin namespace block
namespace COMMON
{

ChannelFull::ChannelFull()
{
	this->_ConstructorID = -815795177;
}

ChannelFull::ChannelFull(bool can_view_participants, bool can_set_username, bool can_set_stickers, int32 id, FString about, int32 participants_count, int32 admins_count, int32 kicked_count, int32 banned_count, int32 read_inbox_max_id, int32 read_outbox_max_id, int32 unread_count, COMMON::Photo* chat_photo, COMMON::PeerNotifySettings* notify_settings, PRIVATE::ExportedChatInvite* exported_invite, TArray<COMMON::BotInfo*> bot_info, int32 migrated_from_chat_id, int32 migrated_from_max_id, int32 pinned_msg_id, COMMON::StickerSet* stickerset)
{
	this->_ConstructorID = -815795177;
	this->can_view_participants = can_view_participants;
	this->can_set_username = can_set_username;
	this->can_set_stickers = can_set_stickers;
	this->id = id;
	this->about = about;
	this->participants_count = participants_count;
	this->admins_count = admins_count;
	this->kicked_count = kicked_count;
	this->banned_count = banned_count;
	this->read_inbox_max_id = read_inbox_max_id;
	this->read_outbox_max_id = read_outbox_max_id;
	this->unread_count = unread_count;
	this->chat_photo = chat_photo;
	this->notify_settings = notify_settings;
	this->exported_invite = exported_invite;
	this->bot_info = bot_info;
	this->migrated_from_chat_id = migrated_from_chat_id;
	this->migrated_from_max_id = migrated_from_max_id;
	this->pinned_msg_id = pinned_msg_id;
	this->stickerset = stickerset;
}
void ChannelFull::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!can_view_participants)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!can_set_username)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(!can_set_stickers)
	{
		Flags |= (1 << 7);
	}
	else
	{
		Flags |= 0;
	}
	if(!participants_count)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!admins_count)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!kicked_count)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!banned_count)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!migrated_from_chat_id)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!migrated_from_max_id)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!pinned_msg_id)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!stickerset)
	{
		Flags |= (1 << 8);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->id);
	Writer.TGWriteString(this->about);
	if(!this->participants_count)
	{
	Writer.WriteInt(this->participants_count);
	}
	if(!this->admins_count)
	{
	Writer.WriteInt(this->admins_count);
	}
	if(!this->kicked_count)
	{
	Writer.WriteInt(this->kicked_count);
	}
	if(!this->banned_count)
	{
	Writer.WriteInt(this->banned_count);
	}
	Writer.WriteInt(this->read_inbox_max_id);
	Writer.WriteInt(this->read_outbox_max_id);
	Writer.WriteInt(this->unread_count);
	this->chat_photo->OnSend(Writer);
	this->notify_settings->OnSend(Writer);
	this->exported_invite->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->bot_info.Num());
	for(auto X : this->bot_info)
	{
	X->OnSend(Writer);
	}
	if(!this->migrated_from_chat_id)
	{
	Writer.WriteInt(this->migrated_from_chat_id);
	}
	if(!this->migrated_from_max_id)
	{
	Writer.WriteInt(this->migrated_from_max_id);
	}
	if(!this->pinned_msg_id)
	{
	Writer.WriteInt(this->pinned_msg_id);
	}
	if(!this->stickerset)
	{
	this->stickerset->OnSend(Writer);
	}
}


void ChannelFull::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 3)) != 0) 
	{
		can_view_participants = true;
	}
	if((Flags & (1 << 6)) != 0) 
	{
		can_set_username = true;
	}
	if((Flags & (1 << 7)) != 0) 
	{
		can_set_stickers = true;
	}
	id = Reader.ReadInt();
	about = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	participants_count = Reader.ReadInt();
	}
	if((Flags & (1 << 1)) != 0) 
	{
	admins_count = Reader.ReadInt();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	kicked_count = Reader.ReadInt();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	banned_count = Reader.ReadInt();
	}
	read_inbox_max_id = Reader.ReadInt();
	read_outbox_max_id = Reader.ReadInt();
	unread_count = Reader.ReadInt();
	chat_photo = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
	notify_settings = reinterpret_cast<COMMON::PeerNotifySettings*>(Reader.TGReadObject());
	exported_invite = reinterpret_cast<PRIVATE::ExportedChatInvite*>(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len22741 = Reader.ReadInt();
	for(int32 i = 0; i < Len22741; i++)
	{
	auto X = reinterpret_cast<COMMON::BotInfo*>(Reader.TGReadObject());
	bot_info.Add(X);
	}
	if((Flags & (1 << 4)) != 0) 
	{
	migrated_from_chat_id = Reader.ReadInt();
	}
	if((Flags & (1 << 4)) != 0) 
	{
	migrated_from_max_id = Reader.ReadInt();
	}
	if((Flags & (1 << 5)) != 0) 
	{
	pinned_msg_id = Reader.ReadInt();
	}
	if((Flags & (1 << 8)) != 0) 
	{
	stickerset = reinterpret_cast<COMMON::StickerSet*>(Reader.TGReadObject());
	}
}
ChannelFull::~ChannelFull()
{

}
}//end namespace block
