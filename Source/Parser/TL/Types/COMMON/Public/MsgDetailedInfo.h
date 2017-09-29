#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MsgDetailedInfo : public TLBaseObject
{
public:
	MsgDetailedInfo();
	MsgDetailedInfo(unsigned long long msg_id, unsigned long long answer_msg_id, int32 bytes, int32 status);

	~MsgDetailedInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetMsgId() const
	{
		 return this->msg_id;
	}

	unsigned long long GetAnswerMsgId() const
	{
		 return this->answer_msg_id;
	}

	int32 Getbytes() const
	{
		 return this->bytes;
	}

	int32 Getstatus() const
	{
		 return this->status;
	}

private:
	unsigned long long msg_id;
	 unsigned long long answer_msg_id;
	 int32 bytes;
	 int32 status;
};
} //end namespace block
