#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "BigInt.h"
#include "BigInt.h"

//begin namespace block
namespace COMMON
{
class PQInnerData : public TLBaseObject
{
public:
	PQInnerData();
	PQInnerData(FString pq, FString p, FString q, TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<256> new_nonce);

	~PQInnerData();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getpq() const
	{
		 return this->pq;
	}

	FString Getp() const
	{
		 return this->p;
	}

	FString Getq() const
	{
		 return this->q;
	}

	TBigInt<128> Getnonce() const
	{
		 return this->nonce;
	}

	TBigInt<128> GetServerNonce() const
	{
		 return this->server_nonce;
	}

	TBigInt<256> GetNewNonce() const
	{
		 return this->new_nonce;
	}

private:
	FString pq;
	 FString p;
	 FString q;
	 TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 TBigInt<256> new_nonce;
};
} //end namespace block
