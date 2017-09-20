#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class InviteToChannel : public TLBaseObject
{
public:
	InviteToChannel();
	InviteToChannel(COMMON::InputChannel* channel, TArray<COMMON::InputUser*> users);

	~InviteToChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputChannel* channel;
	 TArray<COMMON::InputUser*> users;
	COMMON::Updates* result;
};
} //end namespace block
