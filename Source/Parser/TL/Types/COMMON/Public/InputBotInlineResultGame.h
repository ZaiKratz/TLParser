#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputBotInlineResult.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineResultGame : public TLBaseObject
{
public:
	InputBotInlineResultGame();
	InputBotInlineResultGame(FString id, FString short_name, TLBaseObject* send_message);

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

	TLBaseObject*  GetSendMessage() const
	{
		 return this->send_message;
	}

private:
	FString id;
	 FString short_name;
	 TLBaseObject* send_message;
};
} //end namespace block
