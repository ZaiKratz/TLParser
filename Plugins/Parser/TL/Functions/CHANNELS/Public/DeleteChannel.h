#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class DeleteChannel : public TLBaseObject
{
public:
	DeleteChannel();
	DeleteChannel(COMMON::InputChannel* channel);

	~DeleteChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	COMMON::Updates* result;
};
} //end namespace block
