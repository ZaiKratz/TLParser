#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "BigInt.h"

//begin namespace block
namespace COMMON
{
class ClientDHInnerData : public TLBaseObject
{
public:
	ClientDHInnerData();
	ClientDHInnerData(TBigInt<128> nonce, TBigInt<128> server_nonce, unsigned long long retry_id, FString g_b);

	~ClientDHInnerData();
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

	unsigned long long GetRetryId() const
	{
		 return this->retry_id;
	}

	FString GetGB() const
	{
		 return this->g_b;
	}

private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 unsigned long long retry_id;
	 FString g_b;
};
} //end namespace block
