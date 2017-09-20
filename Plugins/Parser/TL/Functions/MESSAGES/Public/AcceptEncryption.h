#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputEncryptedChat.h"
#include "../../../Types/Common/Public/EncryptedChat.h"

//begin namespace block
namespace MESSAGES
{
class AcceptEncryption : public TLBaseObject
{
public:
	AcceptEncryption();
	AcceptEncryption(COMMON::InputEncryptedChat* peer, TArray<uint8> g_b, unsigned long long key_fingerprint);

	~AcceptEncryption();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputEncryptedChat* peer;
	 TArray<uint8> g_b;
	 unsigned long long key_fingerprint;
	COMMON::EncryptedChat* result;
};
} //end namespace block
