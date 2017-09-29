#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageFwdHeader : public TLBaseObject
{
public:
	MessageFwdHeader();
	MessageFwdHeader(int32 from_id, FDateTime date, int32 channel_id, int32 channel_post, FString post_author);

	~MessageFwdHeader();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetFromId() const
	{
		 return this->from_id;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 GetChannelId() const
	{
		 return this->channel_id;
	}

	int32 GetChannelPost() const
	{
		 return this->channel_post;
	}

	FString GetPostAuthor() const
	{
		 return this->post_author;
	}

private:
	int32 from_id;
	 FDateTime date;
	 int32 channel_id;
	 int32 channel_post;
	 FString post_author;
};
} //end namespace block
