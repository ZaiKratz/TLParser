#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MsgResendReq : public TLBaseObject
{
public:
	MsgResendReq();
	MsgResendReq(TArray<unsigned long long> msg_ids);

	~MsgResendReq();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<unsigned long long>  GetMsgIds() const
	{
		 return this->msg_ids;
	}

private:
	TArray<unsigned long long> msg_ids;
};
} //end namespace block
