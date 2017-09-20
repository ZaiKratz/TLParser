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
private:
	int32 chat_id;
	 TArray<COMMON::ChatParticipant*> participants;
	 int32 version;
};
} //end namespace block
