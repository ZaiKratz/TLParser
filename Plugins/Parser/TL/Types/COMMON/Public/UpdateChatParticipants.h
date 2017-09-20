#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/ChatParticipants.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChatParticipants : public PRIVATE::Update
{
public:
	UpdateChatParticipants();
	UpdateChatParticipants(COMMON::ChatParticipants* participants);

	~UpdateChatParticipants();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::ChatParticipants* participants;
};
} //end namespace block
