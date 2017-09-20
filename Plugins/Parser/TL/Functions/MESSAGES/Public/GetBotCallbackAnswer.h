#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Messages/Public/BotCallbackAnswer.h"

//begin namespace block
namespace MESSAGES
{
class GetBotCallbackAnswer : public TLBaseObject
{
public:
	GetBotCallbackAnswer();
	GetBotCallbackAnswer(bool game, PRIVATE::InputPeer* peer, int32 msg_id, TArray<uint8> data);

	~GetBotCallbackAnswer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool game;
	 PRIVATE::InputPeer* peer;
	 int32 msg_id;
	 TArray<uint8> data;
	MESSAGES::BotCallbackAnswer* result;
};
} //end namespace block
