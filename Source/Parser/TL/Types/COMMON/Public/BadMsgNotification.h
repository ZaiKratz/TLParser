#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class BadMsgNotification : public TLBaseObject
{
public:
	BadMsgNotification();
	BadMsgNotification(unsigned long long bad_msg_id, int32 bad_msg_seqno, int32 error_code);

	~BadMsgNotification();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetBadMsgId() const
	{
		 return this->bad_msg_id;
	}

	int32 GetBadMsgSeqno() const
	{
		 return this->bad_msg_seqno;
	}

	int32 GetErrorCode() const
	{
		 return this->error_code;
	}

private:
	unsigned long long bad_msg_id;
	 int32 bad_msg_seqno;
	 int32 error_code;
};
} //end namespace block