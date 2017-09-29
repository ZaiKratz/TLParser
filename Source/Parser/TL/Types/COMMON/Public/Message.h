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

	bool Getout() const
	{
		 return this->out;
	}

	bool Getmentioned() const
	{
		 return this->mentioned;
	}

	bool GetMediaUnread() const
	{
		 return this->media_unread;
	}

	bool Getsilent() const
	{
		 return this->silent;
	}

	bool Getpost() const
	{
		 return this->post;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	int32 GetFromId() const
	{
		 return this->from_id;
	}

	PRIVATE::Peer*  GetToId() const
	{
		 return this->to_id;
	}

	COMMON::MessageFwdHeader*  GetFwdFrom() const
	{
		 return this->fwd_from;
	}

	int32 GetViaBotId() const
	{
		 return this->via_bot_id;
	}

	int32 GetReplyToMsgId() const
	{
		 return this->reply_to_msg_id;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	PRIVATE::MessageMedia*  Getmedia() const
	{
		 return this->media;
	}

	PRIVATE::ReplyMarkup*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

	TArray<PRIVATE::MessageEntity*>  Getentities() const
	{
		 return this->entities;
	}

	int32 Getviews() const
	{
		 return this->views;
	}

	FDateTime GetEditDate() const
	{
		 return this->edit_date;
	}

	FString GetPostAuthor() const
	{
		 return this->post_author;
	}

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
