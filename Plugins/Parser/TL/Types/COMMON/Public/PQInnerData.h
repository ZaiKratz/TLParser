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
private:
	FString pq;
	 FString p;
	 FString q;
	 TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 TBigInt<256> new_nonce;
};
} //end namespace block
