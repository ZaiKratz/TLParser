#pragma once
#include "Engine.h"
#include "../../../Types/Private/ServerDHParams.h"

#include "BigInt.h"
#include "../../../Types/Private/ServerDHParams.h"

//begin namespace block
namespace COMMON
{
class ServerDHParamsOk : public PRIVATE::ServerDHParams
{
public:
	ServerDHParamsOk();
	ServerDHParamsOk(TBigInt<128> nonce, TBigInt<128> server_nonce, FString encrypted_answer);

	~ServerDHParamsOk();
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

	FString GetEncryptedAnswer() const
	{
		 return this->encrypted_answer;
	}

private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 FString encrypted_answer;
};
} //end namespace block
