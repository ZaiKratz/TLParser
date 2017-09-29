#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class BotCallbackAnswer : public TLBaseObject
{
public:
	BotCallbackAnswer();
	BotCallbackAnswer(bool alert, bool has_url, FString message, FString url, int32 cache_time);

	~BotCallbackAnswer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getalert() const
	{
		 return this->alert;
	}

	bool GetHasUrl() const
	{
		 return this->has_url;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	FString Geturl() const
	{
		 return this->url;
	}

	int32 GetCacheTime() const
	{
		 return this->cache_time;
	}

private:
	bool alert;
	 bool has_url;
	 FString message;
	 FString url;
	 int32 cache_time;
};
} //end namespace block
