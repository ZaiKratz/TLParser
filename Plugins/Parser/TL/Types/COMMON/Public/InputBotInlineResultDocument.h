#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"
#include "../../../Types/Private/InputBotInlineMessage.h"
#include "../../../Types/Common/Public/InputBotInlineResult.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineResultDocument : public TLBaseObject
{
public:
	InputBotInlineResultDocument();
	InputBotInlineResultDocument(FString id, FString type, FString title, FString description, COMMON::InputDocument* document, PRIVATE::InputBotInlineMessage* send_message);

	~InputBotInlineResultDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString id;
	 FString type;
	 FString title;
	 FString description;
	 COMMON::InputDocument* document;
	 PRIVATE::InputBotInlineMessage* send_message;
};
} //end namespace block
