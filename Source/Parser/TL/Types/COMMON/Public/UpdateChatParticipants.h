#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatParticipants.h"

//begin namespace block
namespace COMMON
{
class UpdateChatParticipants : public TLBaseObject
{
public:
	UpdateChatParticipants();
	UpdateChatParticipants(COMMON::ChatParticipants* participants);

	~UpdateChatParticipants();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::ChatParticipants*  Getparticipants() const
	{
		 return this->participants;
	}

private:
	COMMON::ChatParticipants* participants;
};
} //end namespace block
