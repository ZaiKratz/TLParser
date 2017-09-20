#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChatParticipantDelete : public PRIVATE::Update
{
public:
	UpdateChatParticipantDelete();
	UpdateChatParticipantDelete(int32 chat_id, int32 user_id, int32 version);

	~UpdateChatParticipantDelete();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	 int32 user_id;
	 int32 version;
};
} //end namespace block
