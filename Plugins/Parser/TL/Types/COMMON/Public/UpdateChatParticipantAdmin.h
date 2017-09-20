#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateChatParticipantAdmin : public PRIVATE::Update
{
public:
	UpdateChatParticipantAdmin();
	UpdateChatParticipantAdmin(int32 chat_id, int32 user_id, bool is_admin, int32 version);

	~UpdateChatParticipantAdmin();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
	 int32 user_id;
	 bool is_admin;
	 int32 version;
};
} //end namespace block
