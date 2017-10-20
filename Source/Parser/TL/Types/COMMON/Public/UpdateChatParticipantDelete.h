#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateChatParticipantDelete : public TLBaseObject
{
public:
	UpdateChatParticipantDelete();
	UpdateChatParticipantDelete(int32 chat_id, int32 user_id, int32 version);

	~UpdateChatParticipantDelete();
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

	int32 Getversion() const
	{
		 return this->version;
	}

private:
	int32 chat_id;
	 int32 user_id;
	 int32 version;
};
} //end namespace block
