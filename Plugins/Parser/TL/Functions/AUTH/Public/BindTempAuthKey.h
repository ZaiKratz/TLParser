#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class BindTempAuthKey : public TLBaseObject
{
public:
	BindTempAuthKey();
	BindTempAuthKey(unsigned long long perm_auth_key_id, unsigned long long nonce, FDateTime expires_at, TArray<uint8> encrypted_message);

	~BindTempAuthKey();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long perm_auth_key_id;
	 unsigned long long nonce;
	 FDateTime expires_at;
	 TArray<uint8> encrypted_message;
	bool result;
};
} //end namespace block
