#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/NotifyPeer.h"
#include "../../../Types/Common/Public/PeerNotifySettings.h"

//begin namespace block
namespace COMMON
{
class UpdateNotifySettings : public TLBaseObject
{
public:
	UpdateNotifySettings();
	UpdateNotifySettings(COMMON::NotifyPeer* peer, COMMON::PeerNotifySettings* notify_settings);

	~UpdateNotifySettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::NotifyPeer*  Getpeer() const
	{
		 return this->peer;
	}

	COMMON::PeerNotifySettings*  GetNotifySettings() const
	{
		 return this->notify_settings;
	}

private:
	COMMON::NotifyPeer* peer;
	 COMMON::PeerNotifySettings* notify_settings;
};
} //end namespace block
