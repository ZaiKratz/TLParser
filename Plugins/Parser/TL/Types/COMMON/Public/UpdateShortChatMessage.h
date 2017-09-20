#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/MessageFwdHeader.h"
#include "../../../Types/Private/MessageEntity.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace COMMON
{
class UpdateShortChatMessage : public TLBaseObject
{
public:
	UpdateShortChatMessage();
	UpdateShortChatMessage(bool out, bool mentioned, bool media_unread, bool silent, int32 id, int32 from_id, int32 chat_id, FString message, int32 pts, int32 pts_count, FDateTime date, COMMON::MessageFwdHeader* fwd_from, int32 via_bot_id, int32 reply_to_msg_id, TArray<PRIVATE::MessageEntity*> entities);

	~UpdateShortChatMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool out;
	 bool mentioned;
	 bool media_unread;
	 bool silent;
	 int32 id;
	 int32 from_id;
	 int32 chat_id;
	 FString message;
	 int32 pts;
	 int32 pts_count;
	 FDateTime date;
	 COMMON::MessageFwdHeader* fwd_from;
	 int32 via_bot_id;
	 int32 reply_to_msg_id;
	 TArray<PRIVATE::MessageEntity*> entities;
};
} //end namespace block
