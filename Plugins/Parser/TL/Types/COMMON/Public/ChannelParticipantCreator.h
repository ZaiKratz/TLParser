#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChannelParticipant.h"

//begin namespace block
namespace COMMON
{
class ChannelParticipantCreator : public TLBaseObject
{
public:
	ChannelParticipantCreator();
	ChannelParticipantCreator(int32 user_id);

	~ChannelParticipantCreator();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
};
} //end namespace block
