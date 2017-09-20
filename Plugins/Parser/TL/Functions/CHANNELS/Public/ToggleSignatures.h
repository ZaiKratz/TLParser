#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class ToggleSignatures : public TLBaseObject
{
public:
	ToggleSignatures();
	ToggleSignatures(COMMON::InputChannel* channel, bool enabled);

	~ToggleSignatures();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	 bool enabled;
	COMMON::Updates* result;
};
} //end namespace block
