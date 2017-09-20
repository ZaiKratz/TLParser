#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/EncryptedMessage.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateNewEncryptedMessage : public PRIVATE::Update
{
public:
	UpdateNewEncryptedMessage();
	UpdateNewEncryptedMessage(COMMON::EncryptedMessage* message, int32 qts);

	~UpdateNewEncryptedMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::EncryptedMessage* message;
	 int32 qts;
};
} //end namespace block
