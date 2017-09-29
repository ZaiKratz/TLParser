#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/EncryptedMessage.h"

//begin namespace block
namespace COMMON
{
class EncryptedMessageService : public TLBaseObject
{
public:
	EncryptedMessageService();
	EncryptedMessageService(unsigned long long random_id, int32 chat_id, FDateTime date, TArray<uint8> bytes);

	~EncryptedMessageService();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetRandomId() const
	{
		 return this->random_id;
	}

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	TArray<uint8>  Getbytes() const
	{
		 return this->bytes;
	}

private:
	unsigned long long random_id;
	 int32 chat_id;
	 FDateTime date;
	 TArray<uint8> bytes;
};
} //end namespace block
