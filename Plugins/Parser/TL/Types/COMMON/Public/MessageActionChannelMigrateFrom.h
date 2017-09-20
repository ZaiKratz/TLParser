#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionChannelMigrateFrom : public PRIVATE::MessageAction
{
public:
	MessageActionChannelMigrateFrom();
	MessageActionChannelMigrateFrom(FString title, int32 chat_id);

	~MessageActionChannelMigrateFrom();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString title;
	 int32 chat_id;
};
} //end namespace block
