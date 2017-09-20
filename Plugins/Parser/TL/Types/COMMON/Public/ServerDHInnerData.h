#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "BigInt.h"

//begin namespace block
namespace COMMON
{
class ServerDHInnerData : public TLBaseObject
{
public:
	ServerDHInnerData();
	ServerDHInnerData(TBigInt<128> nonce, TBigInt<128> server_nonce, int32 g, FString dh_prime, FString g_a, int32 server_time);

	~ServerDHInnerData();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 int32 g;
	 FString dh_prime;
	 FString g_a;
	 int32 server_time;
};
} //end namespace block
