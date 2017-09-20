#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputEncryptedChat.h"
#include "../../../Types/Messages/Public/SentEncryptedMessage.h"

//begin namespace block
namespace MESSAGES
{
class SendEncrypted : public TLBaseObject
{
public:
	SendEncrypted();
	SendEncrypted(COMMON::InputEncryptedChat* peer, unsigned long long random_id, TArray<uint8> data);

	~SendEncrypted();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputEncryptedChat* peer;
	 unsigned long long random_id;
	 TArray<uint8> data;
	MESSAGES::SentEncryptedMessage* result;
};
} //end namespace block
