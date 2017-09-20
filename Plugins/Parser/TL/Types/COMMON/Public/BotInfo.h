#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/BotCommand.h"

//begin namespace block
namespace COMMON
{
class BotInfo : public TLBaseObject
{
public:
	BotInfo();
	BotInfo(int32 user_id, FString description, TArray<COMMON::BotCommand*> commands);

	~BotInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 FString description;
	 TArray<COMMON::BotCommand*> commands;
};
} //end namespace block
