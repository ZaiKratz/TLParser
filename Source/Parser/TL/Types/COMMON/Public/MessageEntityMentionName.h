#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageEntityMentionName : public TLBaseObject
{
public:
	MessageEntityMentionName();
	MessageEntityMentionName(int32 offset, int32 length, int32 user_id);

	~MessageEntityMentionName();
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

	int32 GetUserId() const
	{
		 return this->user_id;
	}

private:
	int32 offset;
	 int32 length;
	 int32 user_id;
};
} //end namespace block
