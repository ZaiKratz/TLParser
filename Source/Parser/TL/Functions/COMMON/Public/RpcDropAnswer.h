#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class RpcDropAnswer : public TLBaseObject
{
public:
	RpcDropAnswer();
	RpcDropAnswer(unsigned long long req_msg_id);

	~RpcDropAnswer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetReqMsgId() const
	{
		 return this->req_msg_id;
	}

	COMMON::RpcDropAnswer* GetResult() const
	{
		 return this->result;
	}

private:
	unsigned long long req_msg_id;
	COMMON::RpcDropAnswer* result;
};
} //end namespace block
