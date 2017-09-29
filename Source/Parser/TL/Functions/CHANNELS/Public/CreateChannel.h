#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class CreateChannel : public TLBaseObject
{
public:
	CreateChannel();
	CreateChannel(bool broadcast, bool megagroup, FString title, FString about);

	~CreateChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getbroadcast() const
	{
		 return this->broadcast;
	}

	bool Getmegagroup() const
	{
		 return this->megagroup;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getabout() const
	{
		 return this->about;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	bool broadcast;
	 bool megagroup;
	 FString title;
	 FString about;
	COMMON::Updates* result;
};
} //end namespace block
