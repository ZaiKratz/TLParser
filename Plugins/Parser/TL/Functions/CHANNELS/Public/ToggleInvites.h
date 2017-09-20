#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class ToggleInvites : public TLBaseObject
{
public:
	ToggleInvites();
	ToggleInvites(COMMON::InputChannel* channel, bool enabled);

	~ToggleInvites();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	 bool enabled;
	COMMON::Updates* result;
};
} //end namespace block
