#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Contacts/Public/TopPeers.h"

//begin namespace block
namespace CONTACTS
{
class TopPeersNotModified : public TLBaseObject
{
public:
	TopPeersNotModified();
	~TopPeersNotModified();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
