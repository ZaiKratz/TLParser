#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionChatEditTitle : public PRIVATE::MessageAction
{
public:
	MessageActionChatEditTitle();
	MessageActionChatEditTitle(FString title);

	~MessageActionChatEditTitle();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gettitle() const
	{
		 return this->title;
	}

private:
	FString title;
};
} //end namespace block
