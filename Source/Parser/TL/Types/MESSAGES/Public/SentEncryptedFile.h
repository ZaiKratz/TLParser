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

	FDateTime Getdate() const
	{
		 return this->date;
	}

	COMMON::EncryptedFile*  Getfile() const
	{
		 return this->file;
	}

private:
	FDateTime date;
	 COMMON::EncryptedFile* file;
};
} //end namespace block
