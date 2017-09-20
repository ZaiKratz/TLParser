#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionChatCreate : public PRIVATE::MessageAction
{
public:
	MessageActionChatCreate();
	MessageActionChatCreate(FString title, TArray<int32> users);

	~MessageActionChatCreate();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString title;
	 TArray<int32> users;
};
} //end namespace block
