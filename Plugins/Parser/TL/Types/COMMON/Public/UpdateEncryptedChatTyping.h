#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateEncryptedChatTyping : public PRIVATE::Update
{
public:
	UpdateEncryptedChatTyping();
	UpdateEncryptedChatTyping(int32 chat_id);

	~UpdateEncryptedChatTyping();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 chat_id;
};
} //end namespace block
