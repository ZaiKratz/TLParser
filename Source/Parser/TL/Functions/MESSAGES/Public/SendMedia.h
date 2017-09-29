#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Private/InputMedia.h"
#include "../../../Types/Private/ReplyMarkup.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class SendMedia : public TLBaseObject
{
public:
	SendMedia();
	SendMedia(bool silent, bool background, bool clear_draft, PRIVATE::InputPeer* peer, int32 reply_to_msg_id, PRIVATE::InputMedia* media, unsigned long long random_id, PRIVATE::ReplyMarkup* reply_markup);

	~SendMedia();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getsilent() const
	{
		 return this->silent;
	}

	bool Getbackground() const
	{
		 return this->background;
	}

	bool GetClearDraft() const
	{
		 return this->clear_draft;
	}

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	int32 GetReplyToMsgId() const
	{
		 return this->reply_to_msg_id;
	}

	PRIVATE::InputMedia*  Getmedia() const
	{
		 return this->media;
	}

	unsigned long long GetRandomId() const
	{
		 return this->random_id;
	}

	PRIVATE::ReplyMarkup*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	bool silent;
	 bool background;
	 bool clear_draft;
	 PRIVATE::InputPeer* peer;
	 int32 reply_to_msg_id;
	 PRIVATE::InputMedia* media;
	 unsigned long long random_id;
	 PRIVATE::ReplyMarkup* reply_markup;
	COMMON::Updates* result;
};
} //end namespace block
