#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputNotifyPeer.h"
#include "../../../Types/Common/Public/PeerNotifySettings.h"

//begin namespace block
namespace ACCOUNT
{
class GetNotifySettings : public TLBaseObject
{
public:
	GetNotifySettings();
	GetNotifySettings(COMMON::InputNotifyPeer* peer);

	~GetNotifySettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputNotifyPeer* peer;
	COMMON::PeerNotifySettings* result;
};
} //end namespace block
