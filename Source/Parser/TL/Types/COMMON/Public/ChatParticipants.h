#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatParticipant.h"

//begin namespace block
namespace COMMON
{
class ChatParticipants : public TLBaseObject
{
public:
	ChatParticipants();
	ChatParticipants(int32 chat_id, TArray<COMMON::ChatParticipant*> participants, int32 version);

	~ChatParticipants();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	TArray<COMMON::ChatParticipant*>  Getparticipants() const
	{
		 return this->participants;
	}

	int32 Getversion() const
	{
		 return this->version;
	}

private:
	int32 chat_id;
	 TArray<COMMON::ChatParticipant*> participants;
	 int32 version;
};
} //end namespace block
