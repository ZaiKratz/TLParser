#pragma once
#include "Engine.h"
#include "../../../Types/Private/PeerNotifyEvents.h"

#include "../../../Types/Private/PeerNotifyEvents.h"

//begin namespace block
namespace COMMON
{
class PeerNotifyEventsAll : public PRIVATE::PeerNotifyEvents
{
public:
	PeerNotifyEventsAll();
	~PeerNotifyEventsAll();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
