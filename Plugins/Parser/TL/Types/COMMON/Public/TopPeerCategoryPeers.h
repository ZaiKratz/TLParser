#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/TopPeerCategory.h"
#include "../../../Types/Common/Public/TopPeer.h"

//begin namespace block
namespace COMMON
{
class TopPeerCategoryPeers : public TLBaseObject
{
public:
	TopPeerCategoryPeers();
	TopPeerCategoryPeers(PRIVATE::TopPeerCategory* category, int32 count, TArray<COMMON::TopPeer*> peers);

	~TopPeerCategoryPeers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::TopPeerCategory* category;
	 int32 count;
	 TArray<COMMON::TopPeer*> peers;
};
} //end namespace block
