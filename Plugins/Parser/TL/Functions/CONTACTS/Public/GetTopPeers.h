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
