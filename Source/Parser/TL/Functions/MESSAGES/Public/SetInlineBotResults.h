#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputBotInlineResult.h"
#include "../../../Types/Common/Public/InlineBotSwitchPM.h"

//begin namespace block
namespace MESSAGES
{
class SetInlineBotResults : public TLBaseObject
{
public:
	SetInlineBotResults();
	SetInlineBotResults(bool gallery, bool Private, unsigned long long query_id, TArray<COMMON::InputBotInlineResult*> results, int32 cache_time, FString next_offset, COMMON::InlineBotSwitchPM* switch_pm);

	~SetInlineBotResults();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getgallery() const
	{
		 return this->gallery;
	}

	bool GetPrivate() const
	{
		 return this->Private;
	}

	unsigned long long GetQueryId() const
	{
		 return this->query_id;
	}

	TArray<COMMON::InputBotInlineResult*>  Getresults() const
	{
		 return this->results;
	}

	int32 GetCacheTime() const
	{
		 return this->cache_time;
	}

	FString GetNextOffset() const
	{
		 return this->next_offset;
	}

	COMMON::InlineBotSwitchPM*  GetSwitchPm() const
	{
		 return this->switch_pm;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool gallery;
	 bool Private;
	 unsigned long long query_id;
	 TArray<COMMON::InputBotInlineResult*> results;
	 int32 cache_time;
	 FString next_offset;
	 COMMON::InlineBotSwitchPM* switch_pm;
	bool result;
};
} //end namespace block
