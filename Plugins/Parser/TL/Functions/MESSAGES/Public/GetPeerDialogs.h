#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Messages/Public/PeerDialogs.h"

//begin namespace block
namespace MESSAGES
{
class GetPeerDialogs : public TLBaseObject
{
public:
	GetPeerDialogs();
	GetPeerDialogs(TArray<PRIVATE::InputPeer*> peers);

	~GetPeerDialogs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<PRIVATE::InputPeer*> peers;
	MESSAGES::PeerDialogs* result;
};
} //end namespace block
