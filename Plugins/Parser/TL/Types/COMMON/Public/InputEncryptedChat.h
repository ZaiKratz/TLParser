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
private:
	int32 chat_id;
	 unsigned long long access_hash;
};
} //end namespace block
