#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoto.h"
#include "../../../Types/Private/InputBotInlineMessage.h"
#include "../../../Types/Common/Public/InputBotInlineResult.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineResultPhoto : public TLBaseObject
{
public:
	InputBotInlineResultPhoto();
	InputBotInlineResultPhoto(FString id, FString type, COMMON::InputPhoto* photo, PRIVATE::InputBotInlineMessage* send_message);

	~InputBotInlineResultPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString id;
	 FString type;
	 COMMON::InputPhoto* photo;
	 PRIVATE::InputBotInlineMessage* send_message;
};
} //end namespace block
