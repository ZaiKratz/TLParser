#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/BotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class BotInlineResult : public TLBaseObject
{
public:
	BotInlineResult();
	BotInlineResult(FString id, FString type, FString title, FString description, FString url, FString thumb_url, FString content_url, FString content_type, int32 w, int32 h, int32 duration, PRIVATE::BotInlineMessage* send_message);

	~BotInlineResult();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getid() const
	{
		 return this->id;
	}

	FString Gettype() const
	{
		 return this->type;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getdescription() const
	{
		 return this->description;
	}

	FString Geturl() const
	{
		 return this->url;
	}

	FString GetThumbUrl() const
	{
		 return this->thumb_url;
	}

	FString GetContentUrl() const
	{
		 return this->content_url;
	}

	FString GetContentType() const
	{
		 return this->content_type;
	}

	int32 Getw() const
	{
		 return this->w;
	}

	int32 Geth() const
	{
		 return this->h;
	}

	int32 Getduration() const
	{
		 return this->duration;
	}

	PRIVATE::BotInlineMessage*  GetSendMessage() const
	{
		 return this->send_message;
	}

private:
	FString id;
	 FString type;
	 FString title;
	 FString description;
	 FString url;
	 FString thumb_url;
	 FString content_url;
	 FString content_type;
	 int32 w;
	 int32 h;
	 int32 duration;
	 PRIVATE::BotInlineMessage* send_message;
};
} //end namespace block