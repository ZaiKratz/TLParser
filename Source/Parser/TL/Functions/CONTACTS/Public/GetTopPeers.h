#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Contacts/Public/TopPeers.h"

//begin namespace block
namespace CONTACTS
{
class GetTopPeers : public TLBaseObject
{
public:
	GetTopPeers();
	GetTopPeers(bool correspondents, bool bots_pm, bool bots_inline, bool phone_calls, bool groups, bool channels, int32 offset, int32 limit, int32 hash);

	~GetTopPeers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getcorrespondents() const
	{
		 return this->correspondents;
	}

	bool GetBotsPm() const
	{
		 return this->bots_pm;
	}

	bool GetBotsInline() const
	{
		 return this->bots_inline;
	}

	bool GetPhoneCalls() const
	{
		 return this->phone_calls;
	}

	bool Getgroups() const
	{
		 return this->groups;
	}

	bool Getchannels() const
	{
		 return this->channels;
	}

	int32 Getoffset() const
	{
		 return this->offset;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	int32 Gethash() const
	{
		 return this->hash;
	}

	CONTACTS::TopPeers* GetResult() const
	{
		 return this->result;
	}

private:
	bool correspondents;
	 bool bots_pm;
	 bool bots_inline;
	 bool phone_calls;
	 bool groups;
	 bool channels;
	 int32 offset;
	 int32 limit;
	 int32 hash;
	CONTACTS::TopPeers* result;
};
} //end namespace block
