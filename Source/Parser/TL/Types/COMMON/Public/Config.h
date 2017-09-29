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

	bool GetPhonecallsEnabled() const
	{
		 return this->phonecalls_enabled;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	FDateTime Getexpires() const
	{
		 return this->expires;
	}

	bool GetTestMode() const
	{
		 return this->test_mode;
	}

	int32 GetThisDc() const
	{
		 return this->this_dc;
	}

	TArray<COMMON::DcOption*>  GetDcOptions() const
	{
		 return this->dc_options;
	}

	int32 GetChatSizeMax() const
	{
		 return this->chat_size_max;
	}

	int32 GetMegagroupSizeMax() const
	{
		 return this->megagroup_size_max;
	}

	int32 GetForwardedCountMax() const
	{
		 return this->forwarded_count_max;
	}

	int32 GetOnlineUpdatePeriodMs() const
	{
		 return this->online_update_period_ms;
	}

	int32 GetOfflineBlurTimeoutMs() const
	{
		 return this->offline_blur_timeout_ms;
	}

	int32 GetOfflineIdleTimeoutMs() const
	{
		 return this->offline_idle_timeout_ms;
	}

	int32 GetOnlineCloudTimeoutMs() const
	{
		 return this->online_cloud_timeout_ms;
	}

	int32 GetNotifyCloudDelayMs() const
	{
		 return this->notify_cloud_delay_ms;
	}

	int32 GetNotifyDefaultDelayMs() const
	{
		 return this->notify_default_delay_ms;
	}

	int32 GetChatBigSize() const
	{
		 return this->chat_big_size;
	}

	int32 GetPushChatPeriodMs() const
	{
		 return this->push_chat_period_ms;
	}

	int32 GetPushChatLimit() const
	{
		 return this->push_chat_limit;
	}

	int32 GetSavedGifsLimit() const
	{
		 return this->saved_gifs_limit;
	}

	int32 GetEditTimeLimit() const
	{
		 return this->edit_time_limit;
	}

	int32 GetRatingEDecay() const
	{
		 return this->rating_e_decay;
	}

	int32 GetStickersRecentLimit() const
	{
		 return this->stickers_recent_limit;
	}

	int32 GetStickersFavedLimit() const
	{
		 return this->stickers_faved_limit;
	}

	int32 GetTmpSessions() const
	{
		 return this->tmp_sessions;
	}

	int32 GetPinnedDialogsCountMax() const
	{
		 return this->pinned_dialogs_count_max;
	}

	int32 GetCallReceiveTimeoutMs() const
	{
		 return this->call_receive_timeout_ms;
	}

	int32 GetCallRingTimeoutMs() const
	{
		 return this->call_ring_timeout_ms;
	}

	int32 GetCallConnectTimeoutMs() const
	{
		 return this->call_connect_timeout_ms;
	}

	int32 GetCallPacketTimeoutMs() const
	{
		 return this->call_packet_timeout_ms;
	}

	FString GetMeUrlPrefix() const
	{
		 return this->me_url_prefix;
	}

	FString GetSuggestedLangCode() const
	{
		 return this->suggested_lang_code;
	}

	int32 GetLangPackVersion() const
	{
		 return this->lang_pack_version;
	}

	TArray<COMMON::DisabledFeature*>  GetDisabledFeatures() const
	{
		 return this->disabled_features;
	}

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
