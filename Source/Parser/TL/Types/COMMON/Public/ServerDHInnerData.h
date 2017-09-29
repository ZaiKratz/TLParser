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

	TBigInt<128> Getnonce() const
	{
		 return this->nonce;
	}

	TBigInt<128> GetServerNonce() const
	{
		 return this->server_nonce;
	}

	int32 Getg() const
	{
		 return this->g;
	}

	FString GetDhPrime() const
	{
		 return this->dh_prime;
	}

	FString GetGA() const
	{
		 return this->g_a;
	}

	int32 GetServerTime() const
	{
		 return this->server_time;
	}

private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 int32 g;
	 FString dh_prime;
	 FString g_a;
	 int32 server_time;
};
} //end namespace block
