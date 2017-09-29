#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChannelParticipant.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace CHANNELS
{
class ChannelParticipants : public TLBaseObject
{
public:
	ChannelParticipants();
	ChannelParticipants(int32 count, TArray<COMMON::ChannelParticipant*> participants, TArray<COMMON::User*> users);

	~ChannelParticipants();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getcount() const
	{
		 return this->count;
	}

	TArray<COMMON::ChannelParticipant*>  Getparticipants() const
	{
		 return this->participants;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

private:
	int32 count;
	 TArray<COMMON::ChannelParticipant*> participants;
	 TArray<COMMON::User*> users;
};
} //end namespace block
