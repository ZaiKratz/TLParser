#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageEntity.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class InputMessageEntityMentionName : public PRIVATE::MessageEntity
{
public:
	InputMessageEntityMentionName();
	InputMessageEntityMentionName(int32 offset, int32 length, COMMON::InputUser* user_id);

	~InputMessageEntityMentionName();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getoffset() const
	{
		 return this->offset;
	}

	int32 Getlength() const
	{
		 return this->length;
	}

	COMMON::InputUser*  GetUserId() const
	{
		 return this->user_id;
	}

private:
	int32 offset;
	 int32 length;
	 COMMON::InputUser* user_id;
};
} //end namespace block
