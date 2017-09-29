#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputBotInlineMessage.h"
#include "../../../Types/Common/Public/InputBotInlineResult.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineResultGame : public TLBaseObject
{
public:
	InputBotInlineResultGame();
	InputBotInlineResultGame(FString id, FString short_name, PRIVATE::InputBotInlineMessage* send_message);

	~InputBotInlineResultGame();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getid() const
	{
		 return this->id;
	}

	FString GetShortName() const
	{
		 return this->short_name;
	}

	PRIVATE::InputBotInlineMessage*  GetSendMessage() const
	{
		 return this->send_message;
	}

private:
	FString id;
	 FString short_name;
	 PRIVATE::InputBotInlineMessage* send_message;
};
} //end namespace block
