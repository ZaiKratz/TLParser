#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/MsgDetailedInfo.h"

//begin namespace block
namespace COMMON
{
class MsgNewDetailedInfo : public TLBaseObject
{
public:
	MsgNewDetailedInfo();
	MsgNewDetailedInfo(unsigned long long answer_msg_id, int32 bytes, int32 status);

	~MsgNewDetailedInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

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
	unsigned long long answer_msg_id;
	 int32 bytes;
	 int32 status;
};
} //end namespace block
