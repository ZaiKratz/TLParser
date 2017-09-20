#pragma once
#include "Engine.h"
#include "../../../Types/Private/ServerDHParams.h"

#include "BigInt.h"
#include "../../../Types/Private/ServerDHParams.h"

//begin namespace block
namespace COMMON
{
class ServerDHParamsFail : public PRIVATE::ServerDHParams
{
public:
	ServerDHParamsFail();
	ServerDHParamsFail(TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<128> new_nonce_hash);

	~ServerDHParamsFail();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TBigInt<128> nonce;
	 TBigInt<128> server_nonce;
	 TBigInt<128> new_nonce_hash;
};
} //end namespace block
