#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "BigInt.h"

//begin namespace block
namespace COMMON
{
class DhGenOk : public TLBaseObject
{
public:
	DhGenOk();
	DhGenOk(TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<128> new_nonce_hash1);

	~DhGenOk();
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

	TBigInt<128> GetNewNonceHash1() const
	{
		 return this->new_nonce_hash1;
	}

private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 TBigInt<128> new_nonce_hash1;
};
} //end namespace block
