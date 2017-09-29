#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace HELP
{
class SetBotUpdatesStatus : public TLBaseObject
{
public:
	SetBotUpdatesStatus();
	SetBotUpdatesStatus(int32 pending_updates_count, FString message);

	~SetBotUpdatesStatus();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetPendingUpdatesCount() const
	{
		 return this->pending_updates_count;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	int32 pending_updates_count;
	 FString message;
	bool result;
};
} //end namespace block
