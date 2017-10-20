#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"
#include "../../../Types/Common/Public/InputBotInlineResult.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineResultDocument : public TLBaseObject
{
public:
	InputBotInlineResultDocument();
	InputBotInlineResultDocument(FString id, FString type, FString title, FString description, COMMON::InputDocument* document, TLBaseObject* send_message);

	~InputBotInlineResultDocument();
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

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getdescription() const
	{
		 return this->description;
	}

	COMMON::InputDocument*  Getdocument() const
	{
		 return this->document;
	}

	TLBaseObject*  GetSendMessage() const
	{
		 return this->send_message;
	}

private:
	FString id;
	 FString type;
	 FString title;
	 FString description;
	 COMMON::InputDocument* document;
	 TLBaseObject* send_message;
};
} //end namespace block
