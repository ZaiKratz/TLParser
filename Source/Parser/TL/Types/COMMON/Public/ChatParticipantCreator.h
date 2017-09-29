#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatParticipant.h"

//begin namespace block
namespace COMMON
{
class ChatParticipantCreator : public TLBaseObject
{
public:
	ChatParticipantCreator();
	ChatParticipantCreator(int32 user_id);

	~ChatParticipantCreator();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

private:
	int32 user_id;
};
} //end namespace block
