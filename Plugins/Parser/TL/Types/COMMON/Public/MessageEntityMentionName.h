#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageEntity.h"

#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class MessageEntityMentionName : public PRIVATE::MessageEntity
{
public:
	MessageEntityMentionName();
	MessageEntityMentionName(int32 offset, int32 length, int32 user_id);

	~MessageEntityMentionName();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 offset;
	 int32 length;
	 int32 user_id;
};
} //end namespace block
