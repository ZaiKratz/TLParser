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
private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 FString pq;
	 TArray<unsigned long long> server_public_key_fingerprints;
};
} //end namespace block
