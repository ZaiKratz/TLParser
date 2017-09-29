#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PeerNotifySettings.h"

//begin namespace block
namespace COMMON
{
class PeerNotifySettingsEmpty : public TLBaseObject
{
public:
	PeerNotifySettingsEmpty();
	~PeerNotifySettingsEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
