#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class UpdatePinnedMessage : public TLBaseObject
{
public:
	UpdatePinnedMessage();
	UpdatePinnedMessage(bool silent, COMMON::InputChannel* channel, int32 id);

	~UpdatePinnedMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool silent;
	 COMMON::InputChannel* channel;
	 int32 id;
	COMMON::Updates* result;
};
} //end namespace block
