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

	FString Getid() const
	{
		 return this->id;
	}

	FString Gettype() const
	{
		 return this->type;
	}

	COMMON::Photo*  Getphoto() const
	{
		 return this->photo;
	}

	COMMON::Document*  Getdocument() const
	{
		 return this->document;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getdescription() const
	{
		 return this->description;
	}

	PRIVATE::BotInlineMessage*  GetSendMessage() const
	{
		 return this->send_message;
	}

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
