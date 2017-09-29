#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "BigInt.h"

//begin namespace block
namespace COMMON
{
class ResPQ : public TLBaseObject
{
public:
	ResPQ();
	ResPQ(TBigInt<128> nonce, TBigInt<128> server_nonce, FString pq, TArray<unsigned long long> server_public_key_fingerprints);

	~ResPQ();
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

	FString Getpq() const
	{
		 return this->pq;
	}

	TArray<unsigned long long>  GetServerPublicKeyFingerprints() const
	{
		 return this->server_public_key_fingerprints;
	}

private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 FString pq;
	 TArray<unsigned long long> server_public_key_fingerprints;
};
} //end namespace block
