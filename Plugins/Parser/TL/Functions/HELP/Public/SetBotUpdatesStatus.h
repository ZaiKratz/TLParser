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
private:
	int32 pending_updates_count;
	 FString message;
	bool result;
};
} //end namespace block
