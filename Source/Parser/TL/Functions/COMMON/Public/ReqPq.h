#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "BigInt.h"
#include "../../../Types/Common/Public/ResPQ.h"

//begin namespace block
namespace COMMON
{
class ReqPq : public TLBaseObject
{
public:
	ReqPq();
	ReqPq(TBigInt<128> nonce);

	~ReqPq();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TBigInt<128> Getnonce() const
	{
		 return this->nonce;
	}

	COMMON::ResPQ* GetResult() const
	{
		 return this->result;
	}

private:
	TBigInt<128> nonce;
	COMMON::ResPQ* result;
};
} //end namespace block
