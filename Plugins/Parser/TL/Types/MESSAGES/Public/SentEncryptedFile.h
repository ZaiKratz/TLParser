#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/EncryptedFile.h"
#include "../../../Types/Messages/Public/SentEncryptedMessage.h"

//begin namespace block
namespace MESSAGES
{
class SentEncryptedFile : public TLBaseObject
{
public:
	SentEncryptedFile();
	SentEncryptedFile(FDateTime date, COMMON::EncryptedFile* file);

	~SentEncryptedFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FDateTime date;
	 COMMON::EncryptedFile* file;
};
} //end namespace block
