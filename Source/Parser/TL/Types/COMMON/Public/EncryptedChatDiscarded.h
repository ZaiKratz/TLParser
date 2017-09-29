#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/EncryptedChat.h"

//begin namespace block
namespace COMMON
{
class EncryptedChatDiscarded : public TLBaseObject
{
public:
	EncryptedChatDiscarded();
	EncryptedChatDiscarded(int32 id);

	~EncryptedChatDiscarded();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getid() const
	{
		 return this->id;
	}

private:
	int32 id;
};
} //end namespace block
