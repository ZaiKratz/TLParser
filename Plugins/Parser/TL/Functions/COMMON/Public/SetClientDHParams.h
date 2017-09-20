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
private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 FString encrypted_data;
	PRIVATE::SetClientDHParamsAnswer* result;
};
} //end namespace block
