#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateChatParticipantAdd : public TLBaseObject
{
public:
	UpdateChatParticipantAdd();
	UpdateChatParticipantAdd(int32 chat_id, int32 user_id, int32 inviter_id, FDateTime date, int32 version);

	~UpdateChatParticipantAdd();
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

	int32 GetInviterId() const
	{
		 return this->inviter_id;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 Getversion() const
	{
		 return this->version;
	}

private:
	int32 chat_id;
	 int32 user_id;
	 int32 inviter_id;
	 FDateTime date;
	 int32 version;
};
} //end namespace block
