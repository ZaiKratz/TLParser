#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ChatParticipant : public TLBaseObject
{
public:
	ChatParticipant();
	ChatParticipant(int32 user_id, int32 inviter_id, FDateTime date);

	~ChatParticipant();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 int32 inviter_id;
	 FDateTime date;
};
} //end namespace block
