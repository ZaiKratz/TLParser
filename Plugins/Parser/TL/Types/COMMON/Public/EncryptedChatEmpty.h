#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/EncryptedChat.h"

//begin namespace block
namespace COMMON
{
class EncryptedChatEmpty : public TLBaseObject
{
public:
	EncryptedChatEmpty();
	EncryptedChatEmpty(int32 id);

	~EncryptedChatEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 id;
};
} //end namespace block
