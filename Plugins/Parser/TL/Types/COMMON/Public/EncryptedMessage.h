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
private:
	unsigned long long random_id;
	 int32 chat_id;
	 FDateTime date;
	 TArray<uint8> bytes;
	 COMMON::EncryptedFile* file;
};
} //end namespace block
