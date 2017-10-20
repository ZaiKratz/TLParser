#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/PeerDialogs.h"

//begin namespace block
namespace MESSAGES
{
class GetPeerDialogs : public TLBaseObject
{
public:
	GetPeerDialogs();
	GetPeerDialogs(TArray<TLBaseObject*> peers);

	~GetPeerDialogs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<TLBaseObject*>  Getpeers() const
	{
		 return this->peers;
	}

	MESSAGES::PeerDialogs* GetResult() const
	{
		 return this->result;
	}

private:
	TArray<TLBaseObject*> peers;
	MESSAGES::PeerDialogs* result;
};
} //end namespace block
