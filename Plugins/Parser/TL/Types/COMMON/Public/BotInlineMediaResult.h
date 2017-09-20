#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/Document.h"
#include "../../../Types/Private/BotInlineMessage.h"
#include "../../../Types/Common/Public/BotInlineResult.h"

//begin namespace block
namespace COMMON
{
class BotInlineMediaResult : public TLBaseObject
{
public:
	BotInlineMediaResult();
	BotInlineMediaResult(FString id, FString type, COMMON::Photo* photo, COMMON::Document* document, FString title, FString description, PRIVATE::BotInlineMessage* send_message);

	~BotInlineMediaResult();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString id;
	 FString type;
	 COMMON::Photo* photo;
	 COMMON::Document* document;
	 FString title;
	 FString description;
	 PRIVATE::BotInlineMessage* send_message;
};
} //end namespace block
