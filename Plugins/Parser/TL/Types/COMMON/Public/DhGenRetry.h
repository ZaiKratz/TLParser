#pragma once
#include "Engine.h"
#include "../../../Types/Private/SetClientDHParamsAnswer.h"

#include "BigInt.h"
#include "../../../Types/Private/SetClientDHParamsAnswer.h"

//begin namespace block
namespace COMMON
{
class DhGenRetry : public PRIVATE::SetClientDHParamsAnswer
{
public:
	DhGenRetry();
	DhGenRetry(TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<128> new_nonce_hash2);

	~DhGenRetry();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 TBigInt<128> new_nonce_hash2;
};
} //end namespace block
