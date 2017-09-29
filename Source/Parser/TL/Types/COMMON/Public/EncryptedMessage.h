#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/EncryptedFile.h"

//begin namespace block
namespace COMMON
{
class EncryptedMessage : public TLBaseObject
{
public:
	EncryptedMessage();
	EncryptedMessage(unsigned long long random_id, int32 chat_id, FDateTime date, TArray<uint8> bytes, COMMON::EncryptedFile* file);

	~EncryptedMessage();
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

	COMMON::EncryptedFile*  Getfile() const
	{
		 return this->file;
	}

private:
	unsigned long long random_id;
	 int32 chat_id;
	 FDateTime date;
	 TArray<uint8> bytes;
	 COMMON::EncryptedFile* file;
};
} //end namespace block
