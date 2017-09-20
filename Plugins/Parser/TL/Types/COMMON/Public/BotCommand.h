#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class BotCommand : public TLBaseObject
{
public:
	BotCommand();
	BotCommand(FString command, FString description);

	~BotCommand();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString command;
	 FString description;
};
} //end namespace block
