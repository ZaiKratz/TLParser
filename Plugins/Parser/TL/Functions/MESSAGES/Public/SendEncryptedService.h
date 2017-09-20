#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputEncryptedChat.h"
#include "../../../Types/Messages/Public/SentEncryptedMessage.h"

//begin namespace block
namespace MESSAGES
{
class SendEncryptedService : public TLBaseObject
{
public:
	SendEncryptedService();
	SendEncryptedService(COMMON::InputEncryptedChat* peer, unsigned long long random_id, TArray<uint8> data);

	~SendEncryptedService();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputEncryptedChat* peer;
	 unsigned long long random_id;
	 TArray<uint8> data;
	MESSAGES::SentEncryptedMessage* result;
};
} //end namespace block
