#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChannelParticipant.h"

//begin namespace block
namespace COMMON
{
class ChannelParticipantSelf : public TLBaseObject
{
public:
	ChannelParticipantSelf();
	ChannelParticipantSelf(int32 user_id, int32 inviter_id, FDateTime date);

	~ChannelParticipantSelf();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 int32 inviter_id;
	 FDateTime date;
};
} //end namespace block
