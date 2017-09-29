#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputEncryptedChat : public TLBaseObject
{
public:
	InputEncryptedChat();
	InputEncryptedChat(int32 chat_id, unsigned long long access_hash);

	~InputEncryptedChat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChatId() const
	{
		 return this->chat_id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

private:
	int32 chat_id;
	 unsigned long long access_hash;
};
} //end namespace block
