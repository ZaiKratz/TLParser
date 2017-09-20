#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/BotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class BotInlineResult : public TLBaseObject
{
public:
	BotInlineResult();
	BotInlineResult(FString id, FString type, FString title, FString description, FString url, FString thumb_url, FString content_url, FString content_type, int32 w, int32 h, int32 duration, PRIVATE::BotInlineMessage* send_message);

	~BotInlineResult();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString id;
	 FString type;
	 FString title;
	 FString description;
	 FString url;
	 FString thumb_url;
	 FString content_url;
	 FString content_type;
	 int32 w;
	 int32 h;
	 int32 duration;
	 PRIVATE::BotInlineMessage* send_message;
};
} //end namespace block
