#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/PeerSettings.h"

//begin namespace block
namespace MESSAGES
{
class GetPeerSettings : public TLBaseObject
{
public:
	GetPeerSettings();
	GetPeerSettings(PRIVATE::InputPeer* peer);

	~GetPeerSettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	COMMON::PeerSettings* GetResult() const
	{
		 return this->result;
	}

private:
	PRIVATE::InputPeer* peer;
	COMMON::PeerSettings* result;
};
} //end namespace block
