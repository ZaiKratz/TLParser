#include "../Public/Config.h"


//begin namespace block
namespace COMMON
{

Config::Config()
{
	this->_ConstructorID = -1913424220;
}

Config::Config(bool phonecalls_enabled, FDateTime date, FDateTime expires, bool test_mode, int32 this_dc, TArray<COMMON::DcOption*>  dc_options, int32 chat_size_max, int32 megagroup_size_max, int32 forwarded_count_max, int32 online_update_period_ms, int32 offline_blur_timeout_ms, int32 offline_idle_timeout_ms, int32 online_cloud_timeout_ms, int32 notify_cloud_delay_ms, int32 notify_default_delay_ms, int32 chat_big_size, int32 push_chat_period_ms, int32 push_chat_limit, int32 saved_gifs_limit, int32 edit_time_limit, int32 rating_e_decay, int32 stickers_recent_limit, int32 stickers_faved_limit, int32 tmp_sessions, int32 pinned_dialogs_count_max, int32 call_receive_timeout_ms, int32 call_ring_timeout_ms, int32 call_connect_timeout_ms, int32 call_packet_timeout_ms, FString me_url_prefix, FString suggested_lang_code, int32 lang_pack_version, TArray<COMMON::DisabledFeature*>  disabled_features)
{
	this->_ConstructorID = -1913424220;
	this->phonecalls_enabled = phonecalls_enabled;
	this->date = date;
	this->expires = expires;
	this->test_mode = test_mode;
	this->this_dc = this_dc;
	this->dc_options = dc_options;
	this->chat_size_max = chat_size_max;
	this->megagroup_size_max = megagroup_size_max;
	this->forwarded_count_max = forwarded_count_max;
	this->online_update_period_ms = online_update_period_ms;
	this->offline_blur_timeout_ms = offline_blur_timeout_ms;
	this->offline_idle_timeout_ms = offline_idle_timeout_ms;
	this->online_cloud_timeout_ms = online_cloud_timeout_ms;
	this->notify_cloud_delay_ms = notify_cloud_delay_ms;
	this->notify_default_delay_ms = notify_default_delay_ms;
	this->chat_big_size = chat_big_size;
	this->push_chat_period_ms = push_chat_period_ms;
	this->push_chat_limit = push_chat_limit;
	this->saved_gifs_limit = saved_gifs_limit;
	this->edit_time_limit = edit_time_limit;
	this->rating_e_decay = rating_e_decay;
	this->stickers_recent_limit = stickers_recent_limit;
	this->stickers_faved_limit = stickers_faved_limit;
	this->tmp_sessions = tmp_sessions;
	this->pinned_dialogs_count_max = pinned_dialogs_count_max;
	this->call_receive_timeout_ms = call_receive_timeout_ms;
	this->call_ring_timeout_ms = call_ring_timeout_ms;
	this->call_connect_timeout_ms = call_connect_timeout_ms;
	this->call_packet_timeout_ms = call_packet_timeout_ms;
	this->me_url_prefix = me_url_prefix;
	this->suggested_lang_code = suggested_lang_code;
	this->lang_pack_version = lang_pack_version;
	this->disabled_features = disabled_features;
}
void Config::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(phonecalls_enabled)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(tmp_sessions)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!suggested_lang_code.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(lang_pack_version)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteDate(this->date);
	Writer.TGWriteDate(this->expires);
	Writer.WriteBool(this->test_mode);
	Writer.WriteInt(this->this_dc);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->dc_options.Num());
	for(auto X : this->dc_options)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(this->chat_size_max);
	Writer.WriteInt(this->megagroup_size_max);
	Writer.WriteInt(this->forwarded_count_max);
	Writer.WriteInt(this->online_update_period_ms);
	Writer.WriteInt(this->offline_blur_timeout_ms);
	Writer.WriteInt(this->offline_idle_timeout_ms);
	Writer.WriteInt(this->online_cloud_timeout_ms);
	Writer.WriteInt(this->notify_cloud_delay_ms);
	Writer.WriteInt(this->notify_default_delay_ms);
	Writer.WriteInt(this->chat_big_size);
	Writer.WriteInt(this->push_chat_period_ms);
	Writer.WriteInt(this->push_chat_limit);
	Writer.WriteInt(this->saved_gifs_limit);
	Writer.WriteInt(this->edit_time_limit);
	Writer.WriteInt(this->rating_e_decay);
	Writer.WriteInt(this->stickers_recent_limit);
	Writer.WriteInt(this->stickers_faved_limit);
	if(this->tmp_sessions)
	{
	Writer.WriteInt(this->tmp_sessions);
	}
	Writer.WriteInt(this->pinned_dialogs_count_max);
	Writer.WriteInt(this->call_receive_timeout_ms);
	Writer.WriteInt(this->call_ring_timeout_ms);
	Writer.WriteInt(this->call_connect_timeout_ms);
	Writer.WriteInt(this->call_packet_timeout_ms);
	Writer.TGWriteString(this->me_url_prefix);
	Writer.TGWriteString(this->suggested_lang_code);
	if(this->lang_pack_version)
	{
	Writer.WriteInt(this->lang_pack_version);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->disabled_features.Num());
	for(auto X : this->disabled_features)
	{
	X->OnSend(Writer);
	}
}


void Config::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 1)) != 0) 
	{
		phonecalls_enabled = true;
	}
	date = Reader.TGReadDate();
	expires = Reader.TGReadDate();
	test_mode = Reader.ReadBool();
	this_dc = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len25228 = Reader.ReadInt();
	for(int32 i = 0; i < Len25228; i++)
	{
	auto X = reinterpret_cast<COMMON::DcOption*>(Reader.TGReadObject());
	dc_options.Add(X);
	}
	chat_size_max = Reader.ReadInt();
	megagroup_size_max = Reader.ReadInt();
	forwarded_count_max = Reader.ReadInt();
	online_update_period_ms = Reader.ReadInt();
	offline_blur_timeout_ms = Reader.ReadInt();
	offline_idle_timeout_ms = Reader.ReadInt();
	online_cloud_timeout_ms = Reader.ReadInt();
	notify_cloud_delay_ms = Reader.ReadInt();
	notify_default_delay_ms = Reader.ReadInt();
	chat_big_size = Reader.ReadInt();
	push_chat_period_ms = Reader.ReadInt();
	push_chat_limit = Reader.ReadInt();
	saved_gifs_limit = Reader.ReadInt();
	edit_time_limit = Reader.ReadInt();
	rating_e_decay = Reader.ReadInt();
	stickers_recent_limit = Reader.ReadInt();
	stickers_faved_limit = Reader.ReadInt();
	if((Flags & (1 << 0)) != 0) 
	{
	tmp_sessions = Reader.ReadInt();
	}
	pinned_dialogs_count_max = Reader.ReadInt();
	call_receive_timeout_ms = Reader.ReadInt();
	call_ring_timeout_ms = Reader.ReadInt();
	call_connect_timeout_ms = Reader.ReadInt();
	call_packet_timeout_ms = Reader.ReadInt();
	me_url_prefix = Reader.TGReadString();
	if((Flags & (1 << 2)) != 0) 
	{
	suggested_lang_code = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	lang_pack_version = Reader.ReadInt();
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len23001 = Reader.ReadInt();
	for(int32 i = 0; i < Len23001; i++)
	{
	auto X = reinterpret_cast<COMMON::DisabledFeature*>(Reader.TGReadObject());
	disabled_features.Add(X);
	}
	this->_Responded = true;
}
Config::~Config()
{
}
}//end namespace block
