#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputBotInlineMessage.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineResult : public TLBaseObject
{
public:
	InputBotInlineResult();
	InputBotInlineResult(FString id, FString type, FString title, FString description, FString url, FString thumb_url, FString content_url, FString content_type, int32 w, int32 h, int32 duration, PRIVATE::InputBotInlineMessage* send_message);

	~InputBotInlineResult();
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
	 PRIVATE::InputBotInlineMessage* send_message;
};
} //end namespace block
