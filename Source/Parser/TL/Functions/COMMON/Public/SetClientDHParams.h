#pragma once
#include "Engine.h"
#include "../../../Types/Private/SetClientDHParamsAnswer.h"

#include "BigInt.h"
#include "../../../Types/Private/SetClientDHParamsAnswer.h"

//begin namespace block
namespace COMMON
{
class SetClientDHParams : public PRIVATE::SetClientDHParamsAnswer
{
public:
	SetClientDHParams();
	SetClientDHParams(TBigInt<128> nonce, TBigInt<128> server_nonce, FString encrypted_data);

	~SetClientDHParams();
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

	FString GetEncryptedData() const
	{
		 return this->encrypted_data;
	}

	PRIVATE::SetClientDHParamsAnswer* GetResult() const
	{
		 return this->result;
	}

private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 FString encrypted_data;
	PRIVATE::SetClientDHParamsAnswer* result;
};
} //end namespace block
