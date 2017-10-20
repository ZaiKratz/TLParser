#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatParticipants.h"
#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/PeerNotifySettings.h"
#include "../../../Types/Common/Public/BotInfo.h"

//begin namespace block
namespace COMMON
{
class ChatFull : public TLBaseObject
{
public:
	ChatFull();
	ChatFull(int32 id, COMMON::ChatParticipants* participants, COMMON::Photo* chat_photo, COMMON::PeerNotifySettings* notify_settings, TLBaseObject* exported_invite, TArray<COMMON::BotInfo*> bot_info);

	~ChatFull();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getid() const
	{
		 return this->id;
	}

	COMMON::ChatParticipants*  Getparticipants() const
	{
		 return this->participants;
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

private:
	int32 id;
	 COMMON::ChatParticipants* participants;
	 COMMON::Photo* chat_photo;
	 COMMON::PeerNotifySettings* notify_settings;
	 TLBaseObject* exported_invite;
	 TArray<COMMON::BotInfo*> bot_info;
};
} //end namespace block
