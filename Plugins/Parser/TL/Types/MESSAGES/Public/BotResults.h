#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InlineBotSwitchPM.h"
#include "../../../Types/Common/Public/BotInlineResult.h"

//begin namespace block
namespace MESSAGES
{
class BotResults : public TLBaseObject
{
public:
	BotResults();
	BotResults(bool gallery, unsigned long long query_id, FString next_offset, COMMON::InlineBotSwitchPM* switch_pm, TArray<COMMON::BotInlineResult*> results, int32 cache_time);

	~BotResults();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool gallery;
	 unsigned long long query_id;
	 FString next_offset;
	 COMMON::InlineBotSwitchPM* switch_pm;
	 TArray<COMMON::BotInlineResult*> results;
	 int32 cache_time;
};
} //end namespace block
