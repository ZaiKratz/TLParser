#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChatParticipantAdd : public PRIVATE::Update
{
public:
	UpdateChatParticipantAdd();
	UpdateChatParticipantAdd(int32 chat_id, int32 user_id, int32 inviter_id, FDateTime date, int32 version);

	~UpdateChatParticipantAdd();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	 int32 user_id;
	 int32 inviter_id;
	 FDateTime date;
	 int32 version;
};
} //end namespace block
