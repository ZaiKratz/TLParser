#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputEncryptedChat.h"
#include "../../../Types/Common/Public/InputEncryptedFile.h"
#include "../../../Types/Messages/Public/SentEncryptedMessage.h"

//begin namespace block
namespace MESSAGES
{
class SendEncryptedFile : public TLBaseObject
{
public:
	SendEncryptedFile();
	SendEncryptedFile(COMMON::InputEncryptedChat* peer, unsigned long long random_id, TArray<uint8> data, COMMON::InputEncryptedFile* file);

	~SendEncryptedFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputEncryptedChat*  Getpeer() const
	{
		 return this->peer;
	}

	unsigned long long GetRandomId() const
	{
		 return this->random_id;
	}

	TArray<uint8>  Getdata() const
	{
		 return this->data;
	}

	COMMON::InputEncryptedFile*  Getfile() const
	{
		 return this->file;
	}

	MESSAGES::SentEncryptedMessage* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputEncryptedChat* peer;
	 unsigned long long random_id;
	 TArray<uint8> data;
	 COMMON::InputEncryptedFile* file;
	MESSAGES::SentEncryptedMessage* result;
};
} //end namespace block
