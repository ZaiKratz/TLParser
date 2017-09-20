#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Messages/Public/ChatFull.h"

//begin namespace block
namespace CHANNELS
{
class GetFullChannel : public TLBaseObject
{
public:
	GetFullChannel();
	GetFullChannel(COMMON::InputChannel* channel);

	~GetFullChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	MESSAGES::ChatFull* result;
};
} //end namespace block
