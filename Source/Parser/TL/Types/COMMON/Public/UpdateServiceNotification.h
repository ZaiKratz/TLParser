#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateServiceNotification : public TLBaseObject
{
public:
	UpdateServiceNotification();
	UpdateServiceNotification(bool popup, FDateTime inbox_date, FString type, FString message, TLBaseObject* media, TArray<TLBaseObject*> entities);

	~UpdateServiceNotification();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getpopup() const
	{
		 return this->popup;
	}

	FDateTime GetInboxDate() const
	{
		 return this->inbox_date;
	}

	FString Gettype() const
	{
		 return this->type;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	TLBaseObject*  Getmedia() const
	{
		 return this->media;
	}

	TArray<TLBaseObject*>  Getentities() const
	{
		 return this->entities;
	}

private:
	bool popup;
	 FDateTime inbox_date;
	 FString type;
	 FString message;
	 TLBaseObject* media;
	 TArray<TLBaseObject*> entities;
};
} //end namespace block
