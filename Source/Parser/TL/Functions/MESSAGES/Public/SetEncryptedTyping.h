#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputEncryptedChat.h"

//begin namespace block
namespace MESSAGES
{
class SetEncryptedTyping : public TLBaseObject
{
public:
	SetEncryptedTyping();
	SetEncryptedTyping(COMMON::InputEncryptedChat* peer, bool typing);

	~SetEncryptedTyping();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputEncryptedChat*  Getpeer() const
	{
		 return this->peer;
	}

	bool Gettyping() const
	{
		 return this->typing;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputEncryptedChat* peer;
	 bool typing;
	bool result;
};
} //end namespace block
