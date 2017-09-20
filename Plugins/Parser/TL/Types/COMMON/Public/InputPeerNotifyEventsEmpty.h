#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputPeerNotifyEvents.h"

#include "../../../Types/Private/InputPeerNotifyEvents.h"

//begin namespace block
namespace COMMON
{
class InputPeerNotifyEventsEmpty : public PRIVATE::InputPeerNotifyEvents
{
public:
	InputPeerNotifyEventsEmpty();
	~InputPeerNotifyEventsEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
