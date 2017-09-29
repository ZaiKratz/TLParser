#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Chat.h"

//begin namespace block
namespace COMMON
{
class ChannelForbidden : public TLBaseObject
{
public:
	ChannelForbidden();
	ChannelForbidden(bool broadcast, bool megagroup, int32 id, unsigned long long access_hash, FString title, FDateTime until_date);

	~ChannelForbidden();
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

	int32 Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FDateTime GetUntilDate() const
	{
		 return this->until_date;
	}

private:
	bool broadcast;
	 bool megagroup;
	 int32 id;
	 unsigned long long access_hash;
	 FString title;
	 FDateTime until_date;
};
} //end namespace block
