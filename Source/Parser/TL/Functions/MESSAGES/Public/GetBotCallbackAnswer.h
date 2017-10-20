#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/BotCallbackAnswer.h"

//begin namespace block
namespace MESSAGES
{
class GetBotCallbackAnswer : public TLBaseObject
{
public:
	GetBotCallbackAnswer();
	GetBotCallbackAnswer(bool game, TLBaseObject* peer, int32 msg_id, TArray<uint8> data);

	~GetBotCallbackAnswer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getgame() const
	{
		 return this->game;
	}

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	int32 GetMsgId() const
	{
		 return this->msg_id;
	}

	TArray<uint8>  Getdata() const
	{
		 return this->data;
	}

	MESSAGES::BotCallbackAnswer* GetResult() const
	{
		 return this->result;
	}

private:
	bool game;
	 TLBaseObject* peer;
	 int32 msg_id;
	 TArray<uint8> data;
	MESSAGES::BotCallbackAnswer* result;
};
} //end namespace block
