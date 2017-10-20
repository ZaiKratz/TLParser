#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChannelParticipant.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionParticipantInvite : public TLBaseObject
{
public:
	ChannelAdminLogEventActionParticipantInvite();
	ChannelAdminLogEventActionParticipantInvite(COMMON::ChannelParticipant* participant);

	~ChannelAdminLogEventActionParticipantInvite();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::ChannelParticipant*  Getparticipant() const
	{
		 return this->participant;
	}

private:
	COMMON::ChannelParticipant* participant;
};
} //end namespace block
