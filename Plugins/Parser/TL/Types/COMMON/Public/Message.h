#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/Peer.h"
#include "../../../Types/Common/Public/MessageFwdHeader.h"
#include "../../../Types/Private/MessageMedia.h"
#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class Message : public TLBaseObject
{
public:
	Message();
	Message(bool out, bool mentioned, bool media_unread, bool silent, bool post, int32 id, int32 from_id, PRIVATE::Peer* to_id, COMMON::MessageFwdHeader* fwd_from, int32 via_bot_id, int32 reply_to_msg_id, FDateTime date, FString message, PRIVATE::MessageMedia* media, PRIVATE::ReplyMarkup* reply_markup, TArray<PRIVATE::MessageEntity*> entities, int32 views, FDateTime edit_date, FString post_author);

	~Message();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool out;
	 bool mentioned;
	 bool media_unread;
	 bool silent;
	 bool post;
	 int32 id;
	 int32 from_id;
	 PRIVATE::Peer* to_id;
	 COMMON::MessageFwdHeader* fwd_from;
	 int32 via_bot_id;
	 int32 reply_to_msg_id;
	 FDateTime date;
	 FString message;
	 PRIVATE::MessageMedia* media;
	 PRIVATE::ReplyMarkup* reply_markup;
	 TArray<PRIVATE::MessageEntity*> entities;
	 int32 views;
	 FDateTime edit_date;
	 FString post_author;
};
} //end namespace block
