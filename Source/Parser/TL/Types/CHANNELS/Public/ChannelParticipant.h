#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChannelParticipant.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CHANNELS
{
class ChannelParticipant : public TLBaseObject
{
public:
	ChannelParticipant();
	ChannelParticipant(COMMON::ChannelParticipant* participant, TArray<COMMON::User*> users);

	~ChannelParticipant();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::ChannelParticipant*  Getparticipant() const
	{
		 return this->participant;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

private:
	COMMON::ChannelParticipant* participant;
	 TArray<COMMON::User*> users;
};
} //end namespace block
