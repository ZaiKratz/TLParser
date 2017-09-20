#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/InputBotInlineMessageID.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateInlineBotCallbackQuery : public PRIVATE::Update
{
public:
	UpdateInlineBotCallbackQuery();
	UpdateInlineBotCallbackQuery(unsigned long long query_id, int32 user_id, COMMON::InputBotInlineMessageID* msg_id, unsigned long long chat_instance, TArray<uint8> data, FString game_short_name);

	~UpdateInlineBotCallbackQuery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long query_id;
	 int32 user_id;
	 COMMON::InputBotInlineMessageID* msg_id;
	 unsigned long long chat_instance;
	 TArray<uint8> data;
	 FString game_short_name;
};
} //end namespace block
