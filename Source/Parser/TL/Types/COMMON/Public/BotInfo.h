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

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	FString Getdescription() const
	{
		 return this->description;
	}

	TArray<COMMON::BotCommand*>  Getcommands() const
	{
		 return this->commands;
	}

private:
	int32 user_id;
	 FString description;
	 TArray<COMMON::BotCommand*> commands;
};
} //end namespace block
