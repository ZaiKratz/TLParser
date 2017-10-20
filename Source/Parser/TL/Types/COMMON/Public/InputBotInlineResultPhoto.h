#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoto.h"
#include "../../../Types/Common/Public/InputBotInlineResult.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineResultPhoto : public TLBaseObject
{
public:
	InputBotInlineResultPhoto();
	InputBotInlineResultPhoto(FString id, FString type, COMMON::InputPhoto* photo, TLBaseObject* send_message);

	~InputBotInlineResultPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getid() const
	{
		 return this->id;
	}

	FString Gettype() const
	{
		 return this->type;
	}

	COMMON::InputPhoto*  Getphoto() const
	{
		 return this->photo;
	}

	TLBaseObject*  GetSendMessage() const
	{
		 return this->send_message;
	}

private:
	FString id;
	 FString type;
	 COMMON::InputPhoto* photo;
	 TLBaseObject* send_message;
};
} //end namespace block
