#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/EncryptedChat.h"

//begin namespace block
namespace COMMON
{
class UpdateEncryption : public TLBaseObject
{
public:
	UpdateEncryption();
	UpdateEncryption(COMMON::EncryptedChat* chat, FDateTime date);

	~UpdateEncryption();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::EncryptedChat*  Getchat() const
	{
		 return this->chat;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

private:
	COMMON::EncryptedChat* chat;
	 FDateTime date;
};
} //end namespace block
