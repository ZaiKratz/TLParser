#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatParticipant.h"
#include "../../../Types/Common/Public/ChatParticipants.h"

//begin namespace block
namespace COMMON
{
class ChatParticipantsForbidden : public TLBaseObject
{
public:
	ChatParticipantsForbidden();
	ChatParticipantsForbidden(int32 chat_id, COMMON::ChatParticipant* self_participant);

	~ChatParticipantsForbidden();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	COMMON::ChatParticipant*  GetSelfParticipant() const
	{
		 return this->self_participant;
	}

private:
	int32 chat_id;
	 COMMON::ChatParticipant* self_participant;
};
} //end namespace block
