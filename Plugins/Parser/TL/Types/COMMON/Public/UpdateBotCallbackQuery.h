#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Peer.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateBotCallbackQuery : public PRIVATE::Update
{
public:
	UpdateBotCallbackQuery();
	UpdateBotCallbackQuery(unsigned long long query_id, int32 user_id, PRIVATE::Peer* peer, int32 msg_id, unsigned long long chat_instance, TArray<uint8> data, FString game_short_name);

	~UpdateBotCallbackQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long query_id;
	 int32 user_id;
	 PRIVATE::Peer* peer;
	 int32 msg_id;
	 unsigned long long chat_instance;
	 TArray<uint8> data;
	 FString game_short_name;
};
} //end namespace block
