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
