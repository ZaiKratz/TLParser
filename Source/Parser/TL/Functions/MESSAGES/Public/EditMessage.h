#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class EditMessage : public TLBaseObject
{
public:
	EditMessage();
	EditMessage(bool no_webpage, TLBaseObject* peer, int32 id, FString message, TLBaseObject* reply_markup, TArray<TLBaseObject*> entities);

	~EditMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetNoWebpage() const
	{
		 return this->no_webpage;
	}

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	TLBaseObject*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

	TArray<TLBaseObject*>  Getentities() const
	{
		 return this->entities;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	bool no_webpage;
	 TLBaseObject* peer;
	 int32 id;
	 FString message;
	 TLBaseObject* reply_markup;
	 TArray<TLBaseObject*> entities;
	COMMON::Updates* result;
};
} //end namespace block
