#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/BadMsgNotification.h"

//begin namespace block
namespace COMMON
{
class BadServerSalt : public TLBaseObject
{
public:
	BadServerSalt();
	BadServerSalt(unsigned long long bad_msg_id, int32 bad_msg_seqno, int32 error_code, unsigned long long new_server_salt);

	~BadServerSalt();
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

	unsigned long long GetNewServerSalt() const
	{
		 return this->new_server_salt;
	}

private:
	unsigned long long bad_msg_id;
	 int32 bad_msg_seqno;
	 int32 error_code;
	 unsigned long long new_server_salt;
};
} //end namespace block
