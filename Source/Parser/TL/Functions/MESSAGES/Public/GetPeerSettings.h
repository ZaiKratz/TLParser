#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PeerSettings.h"

//begin namespace block
namespace MESSAGES
{
class GetPeerSettings : public TLBaseObject
{
public:
	GetPeerSettings();
	GetPeerSettings(TLBaseObject* peer);

	~GetPeerSettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	COMMON::PeerSettings* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* peer;
	COMMON::PeerSettings* result;
};
} //end namespace block
