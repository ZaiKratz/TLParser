#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/NotifyPeer.h"
#include "../../../Types/Common/Public/PeerNotifySettings.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateNotifySettings : public PRIVATE::Update
{
public:
	UpdateNotifySettings();
	UpdateNotifySettings(COMMON::NotifyPeer* peer, COMMON::PeerNotifySettings* notify_settings);

	~UpdateNotifySettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::NotifyPeer* peer;
	 COMMON::PeerNotifySettings* notify_settings;
};
} //end namespace block
