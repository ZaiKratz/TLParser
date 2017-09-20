#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/EncryptedChat.h"

//begin namespace block
namespace MESSAGES
{
class RequestEncryption : public TLBaseObject
{
public:
	RequestEncryption();
	RequestEncryption(COMMON::InputUser* user_id, int32 random_id, TArray<uint8> g_a);

	~RequestEncryption();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputUser* user_id;
	 int32 random_id;
	 TArray<uint8> g_a;
	COMMON::EncryptedChat* result;
};
} //end namespace block
