#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/EncryptedMessage.h"

//begin namespace block
namespace COMMON
{
class UpdateNewEncryptedMessage : public TLBaseObject
{
public:
	UpdateNewEncryptedMessage();
	UpdateNewEncryptedMessage(COMMON::EncryptedMessage* message, int32 qts);

	~UpdateNewEncryptedMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::EncryptedMessage*  Getmessage() const
	{
		 return this->message;
	}

	int32 Getqts() const
	{
		 return this->qts;
	}

private:
	COMMON::EncryptedMessage* message;
	 int32 qts;
};
} //end namespace block
