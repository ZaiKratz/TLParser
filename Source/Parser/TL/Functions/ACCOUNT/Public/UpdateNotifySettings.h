#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputNotifyPeer.h"
#include "../../../Types/Common/Public/InputPeerNotifySettings.h"

//begin namespace block
namespace ACCOUNT
{
class UpdateNotifySettings : public TLBaseObject
{
public:
	UpdateNotifySettings();
	UpdateNotifySettings(COMMON::InputNotifyPeer* peer, COMMON::InputPeerNotifySettings* settings);

	~UpdateNotifySettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputNotifyPeer*  Getpeer() const
	{
		 return this->peer;
	}

	COMMON::InputPeerNotifySettings*  Getsettings() const
	{
		 return this->settings;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputNotifyPeer* peer;
	 COMMON::InputPeerNotifySettings* settings;
	bool result;
};
} //end namespace block
