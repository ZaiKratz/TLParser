#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateChatParticipantAdmin : public TLBaseObject
{
public:
	UpdateChatParticipantAdmin();
	UpdateChatParticipantAdmin(int32 chat_id, int32 user_id, bool is_admin, int32 version);

	~UpdateChatParticipantAdmin();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	bool GetIsAdmin() const
	{
		 return this->is_admin;
	}

	int32 Getversion() const
	{
		 return this->version;
	}

private:
	int32 chat_id;
	 int32 user_id;
	 bool is_admin;
	 int32 version;
};
} //end namespace block
