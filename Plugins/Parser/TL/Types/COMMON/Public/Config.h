#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/DcOption.h"
#include "../../../Types/Common/Public/DisabledFeature.h"

//begin namespace block
namespace COMMON
{
class Config : public TLBaseObject
{
public:
	Config();
	Config(bool phonecalls_enabled, FDateTime date, FDateTime expires, bool test_mode, int32 this_dc, TArray<COMMON::DcOption*> dc_options, int32 chat_size_max, int32 megagroup_size_max, int32 forwarded_count_max, int32 online_update_period_ms, int32 offline_blur_timeout_ms, int32 offline_idle_timeout_ms, int32 online_cloud_timeout_ms, int32 notify_cloud_delay_ms, int32 notify_default_delay_ms, int32 chat_big_size, int32 push_chat_period_ms, int32 push_chat_limit, int32 saved_gifs_limit, int32 edit_time_limit, int32 rating_e_decay, int32 stickers_recent_limit, int32 stickers_faved_limit, int32 tmp_sessions, int32 pinned_dialogs_count_max, int32 call_receive_timeout_ms, int32 call_ring_timeout_ms, int32 call_connect_timeout_ms, int32 call_packet_timeout_ms, FString me_url_prefix, FString suggested_lang_code, int32 lang_pack_version, TArray<COMMON::DisabledFeature*> disabled_features);

	~Config();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool phonecalls_enabled;
	 FDateTime date;
	 FDateTime expires;
	 bool test_mode;
	 int32 this_dc;
	 TArray<COMMON::DcOption*> dc_options;
	 int32 chat_size_max;
	 int32 megagroup_size_max;
	 int32 forwarded_count_max;
	 int32 online_update_period_ms;
	 int32 offline_blur_timeout_ms;
	 int32 offline_idle_timeout_ms;
	 int32 online_cloud_timeout_ms;
	 int32 notify_cloud_delay_ms;
	 int32 notify_default_delay_ms;
	 int32 chat_big_size;
	 int32 push_chat_period_ms;
	 int32 push_chat_limit;
	 int32 saved_gifs_limit;
	 int32 edit_time_limit;
	 int32 rating_e_decay;
	 int32 stickers_recent_limit;
	 int32 stickers_faved_limit;
	 int32 tmp_sessions;
	 int32 pinned_dialogs_count_max;
	 int32 call_receive_timeout_ms;
	 int32 call_ring_timeout_ms;
	 int32 call_connect_timeout_ms;
	 int32 call_packet_timeout_ms;
	 FString me_url_prefix;
	 FString suggested_lang_code;
	 int32 lang_pack_version;
	 TArray<COMMON::DisabledFeature*> disabled_features;
};
} //end namespace block
