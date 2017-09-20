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
private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 FString encrypted_answer;
};
} //end namespace block
