#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class JoinChannel : public TLBaseObject
{
public:
	JoinChannel();
	JoinChannel(COMMON::InputChannel* channel);

	~JoinChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	COMMON::Updates* result;
};
} //end namespace block
