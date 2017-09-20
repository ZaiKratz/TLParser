#pragma once
#include "Engine.h"
#include "../../../Types/Private/SetClientDHParamsAnswer.h"

#include "BigInt.h"
#include "../../../Types/Private/SetClientDHParamsAnswer.h"

//begin namespace block
namespace COMMON
{
class DhGenFail : public PRIVATE::SetClientDHParamsAnswer
{
public:
	DhGenFail();
	DhGenFail(TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<128> new_nonce_hash3);

	~DhGenFail();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 TBigInt<128> new_nonce_hash3;
};
} //end namespace block
