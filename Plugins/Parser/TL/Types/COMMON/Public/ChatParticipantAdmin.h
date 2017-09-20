#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatParticipant.h"

//begin namespace block
namespace COMMON
{
class ChatParticipantAdmin : public TLBaseObject
{
public:
	ChatParticipantAdmin();
	ChatParticipantAdmin(int32 user_id, int32 inviter_id, FDateTime date);

	~ChatParticipantAdmin();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 int32 inviter_id;
	 FDateTime date;
};
} //end namespace block
