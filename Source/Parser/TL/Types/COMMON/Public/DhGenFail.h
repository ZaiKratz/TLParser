#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "BigInt.h"

//begin namespace block
namespace COMMON
{
class DhGenFail : public TLBaseObject
{
public:
	DhGenFail();
	DhGenFail(TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<128> new_nonce_hash3);

	~DhGenFail();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TBigInt<128> Getnonce() const
	{
		 return this->nonce;
	}

	TBigInt<128> GetServerNonce() const
	{
		 return this->server_nonce;
	}

	TBigInt<128> GetNewNonceHash3() const
	{
		 return this->new_nonce_hash3;
	}

private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 TBigInt<128> new_nonce_hash3;
};
} //end namespace block
