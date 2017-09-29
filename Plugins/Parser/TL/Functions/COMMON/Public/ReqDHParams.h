#pragma once
#include "Engine.h"
#include "../../../Types/Private/ServerDHParams.h"

#include "BigInt.h"
#include "../../../Types/Private/ServerDHParams.h"

//begin namespace block
namespace COMMON
{
class ReqDHParams : public PRIVATE::ServerDHParams
{
public:
	ReqDHParams();
	ReqDHParams(TBigInt<128> nonce, TBigInt<128> server_nonce, FString p, FString q, unsigned long long public_key_fingerprint, FString encrypted_data);

	~ReqDHParams();
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

	FString Getp() const
	{
		 return this->p;
	}

	FString Getq() const
	{
		 return this->q;
	}

	unsigned long long GetPublicKeyFingerprint() const
	{
		 return this->public_key_fingerprint;
	}

	FString GetEncryptedData() const
	{
		 return this->encrypted_data;
	}

	PRIVATE::ServerDHParams* GetResult() const
	{
		 return this->result;
	}

private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 FString p;
	 FString q;
	 unsigned long long public_key_fingerprint;
	 FString encrypted_data;
	PRIVATE::ServerDHParams* result;
};
} //end namespace block
