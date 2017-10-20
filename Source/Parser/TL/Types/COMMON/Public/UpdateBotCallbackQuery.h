#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateBotCallbackQuery : public TLBaseObject
{
public:
	UpdateBotCallbackQuery();
	UpdateBotCallbackQuery(unsigned long long query_id, int32 user_id, TLBaseObject* peer, int32 msg_id, unsigned long long chat_instance, TArray<uint8> data, FString game_short_name);

	~UpdateBotCallbackQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetQueryId() const
	{
		 return this->query_id;
	}

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	int32 GetMsgId() const
	{
		 return this->msg_id;
	}

	unsigned long long GetChatInstance() const
	{
		 return this->chat_instance;
	}

	TArray<uint8>  Getdata() const
	{
		 return this->data;
	}

	FString GetGameShortName() const
	{
		 return this->game_short_name;
	}

private:
	unsigned long long query_id;
	 int32 user_id;
	 TLBaseObject* peer;
	 int32 msg_id;
	 unsigned long long chat_instance;
	 TArray<uint8> data;
	 FString game_short_name;
};
} //end namespace block
